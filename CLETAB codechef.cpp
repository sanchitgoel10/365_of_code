#include <bits/stdc++.h>
using namespace std;
int c[401];
void serve(int current,unordered_set<int> &block,int c[],int next,int size){
    int distance=0,key=*block.begin();
    for(auto each:block){
        int tdis=1;
        int tkey=each;
        for(int i=next;i<size;i++){
            if(c[i] == tkey) break;
            else tdis++;
        }
        if(tdis>distance){
            distance=tdis;
            key=tkey;
        }
    }
    block.erase(key);
    block.insert(current);
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	int n,m;
	while(t--){
	    cin>>n>>m;
	    for(int i=0;i<m;i++){
	        cin>>c[i];
	    }
	    unordered_set<int> block;
	    int wipe=0;
	    for(int i=0;i<m;i++){
	        if(block.find(c[i]) != block.end()) continue;
	        else if(block.size() < n){
	            block.insert(c[i]);
	            wipe++;
	        }
	        else{
	            serve(c[i],block,c,i+1,m);
	            wipe++;
	        }
	    }
	    cout<<wipe<<"\n";
	}
	return 0;
}
