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
    cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    For(i,0,n){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    vector<int> s1,s2;
    For(i,0,n){
        For(j,0,n){
            s1.pb(a[i]+b[j]);
        }
    }
    For(i,0,n){
        For(j,0,n){
            s2.pb(-(c[i]+d[j]));
        }
    }
    
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    
    int ans=0;
    For(i,0,s1.size()){
        auto ip=equal_range(s2.begin(),s2.end(),s1[i]);
        int x=(ip.ss-s2.begin());
        int y=(ip.ff-s2.begin());
        ans+=(x-y);
    }
    cout<<ans<<endl;
    
	return 0;
}

