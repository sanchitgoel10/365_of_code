#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main() {
	// your code goes here
	FastRead;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        map<int, int> dp;     // for every gcd we are counting subsequences
        int g=__gcd(a[0],a[1]);
        dp[g]=1;
        map<int ,int> :: iterator it;
        for(int i=2;i<n;i++){
            for(it=dp.begin();it!=dp.end();it++){
                int x=__gcd(it->first,a[i]);      //for every existing gcd we add the next element and find new
                dp[x]+=it->second;                // gcd and add it
            }
            for(int j=0;j<i;j++){
                int z=__gcd(a[i],a[j]);          // we find every pair possible and make new gcd
                dp[z]++;
            }
        }
        cout<<dp[1]<<endl;      //number of subsequences with gcd==1
    }
	return 0;
}
