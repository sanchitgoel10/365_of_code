#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    ll l[n];
	    ll r[n];
	    ll ans=INT_MIN;
	    ll current=0;
	    for(int i=0;i<n;i++){
	        current=max(arr[i],current+arr[i]);
	        ans=max(ans,current);
	        l[i]=current;
	    }
	    current=0;
	    for(int i=n-1;i>=0;i--){
	        current=max(arr[i],current+arr[i]);
	        r[i]=current;
	    }
	    for(int i=1;i<n-1;i++){
	        ans=max(ans,l[i-1]+r[i+1]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
