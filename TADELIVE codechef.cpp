#include <bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
}

int main() {
	// your code goes here
	int n,x,y;
	cin>>n>>x>>y;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
	
	int profit=0;
	vector<pair<int, int> > v;
	for(int i=0;i<n;i++){
	    v.push_back(make_pair(abs(a[i]-b[i]),i));
	}
	sort(v.begin(),v.end(),sortinrev);
	for(int i=0;i<n;i++){
	    if(a[v[i].second]>b[v[i].second]){
	        if(x>0){
	            profit+=a[v[i].second];
	            x--;
	        }else{
	            profit+=b[v[i].second];
	            y--;
	        }
	    }else{
	        if(y>0){
	            profit+=b[v[i].second];
	            y--;
	        }else{
	            profit+=a[v[i].second];
	            x--;
	        }
	        
	    }
	}
	cout<<profit<<endl;
	return 0;
}
