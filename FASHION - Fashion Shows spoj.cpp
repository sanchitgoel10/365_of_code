
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[n],w[n];
		for(int i=0;i<n;i++) cin>>m[i];
		for(int i=0;i<n;i++) cin>>w[i];
		sort(m,m+n);
		sort(w,w+n);
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=m[i]*w[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}