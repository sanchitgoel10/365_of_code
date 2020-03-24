#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin>>tc;
	int c=1;
	while(tc--){
		int n,k;
		ll b,t;
		cin>>n>>k>>b>>t;
		ll x[n];
		ll s[n];
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cin>>s[i];
		int cantreach=0;    // birds that cant reach at all and are a blockers on path
		int canreach=0;   // birds that can reach barn if there is no block in path
		int swaps=0;
		for(int i=n-1;i>=0;i--){
			ll d=b-x[i];
			if(d<=(t*s[i])){
				canreach++;
				if(cantreach>0){
					swaps+=cantreach;    // removing all blocka on path and letting the fast chick go
				}
			}else{
				cantreach++;
			}
			
			if(canreach==k) break;
		}
		if(canreach>=k){
			cout<<"Case #"<<c<<": "<<swaps<<endl;
		}else{
			cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<endl;
		}
		c++;
	}
	return 0;
}