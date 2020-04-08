#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)


int32_t main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int> v(n);
        For(i,0,n)cin>>v[i];
        sort(v.begin(),v.end());
        int ans=0;
        For(i,0,n-1){
            For(j,i+1,n-1){
                int x=v[i]+v[j];
                int ind=upper_bound(v.begin(),v.end(),x)-v.begin();
                if(ind!=n){
                    ans+=n-ind;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}

