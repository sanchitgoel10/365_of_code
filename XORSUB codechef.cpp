#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define frr(i,a,b) for(int i=(a-1);i>=(b);i--)
#define vi vector<int>
#define de deque<int>
#define del deque<ll>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define mpp map<ll,ll>
#define rev(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())
#define ln(a) a.length()
#define sz(a) a.size()
ll M=1000000007;

int main(){
    ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--)
    {
        int n,k;
        cin>>n;cin>>k;
        int a[n];
        f(i,0,n)cin>>a[i];


   int dp[1024];
   memset(dp,0,sizeof dp);
   f(i,0,n)
   {
       int x=a[i];dp[x]=1;
       f(j,0,1024)
       {
           if(dp[j]==1)
           {
               int val=a[i]^j;dp[val]=1;
           }
       }
   }


   int ans=0;
   f(i,0,1024)
   {
      if(dp[i]==1){int res=i^k;ans=max(ans,res);}

   }

        cout<<ans<<endl;
    }
}
