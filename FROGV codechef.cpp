#include <bits/stdc++.h>
using namespace std;
/*One Line Proof : Frog’s reachable from the f in the direction of f1 is also reachable from f1.
Another point to note is that the frog on the extreme positive side of X axis(i.e Maximum A[i] , say A[j]) can communicate till A[j] + K.
*/



bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,k,p;
	cin>>n>>k>>p;
	vector<pair<int, int> > v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i].first;
	    v[i].second=i+1;
	}
	sort(v.begin(), v.end(), sortinrev); 
	map<int ,int> maxd;
	maxd[v[0].second]=v[0].first+k;
	
	for(int i=1;i<n;i++){
	    if(v[i-1].first-v[i].first<=k){
	        maxd[v[i].second]=maxd[v[i-1].second];
	    }else{
	        maxd[v[i].second]=v[i].first+k;
	    }
	}
	while(p--){
	    int x,y;
	    cin>>x>>y;
	    if(maxd[x]==maxd[y]){
	        cout<<"Yes"<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }
	}
	
	
	
	
	return 0;
}
