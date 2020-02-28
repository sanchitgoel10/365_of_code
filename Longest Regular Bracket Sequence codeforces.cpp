#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
string str ;
map<int,int> mp ;
int maxi = 0 ;
stack<int> s ;
int dp[1000005] ;
int cnt ;
void solve()
{
    cin >> str ;
    for(int i=0 ; i<str.size() ; i++)
    {
        if(str[i] == '(')
            s.push(i) ;
        else
        {
            if(s.size()==0)
                continue ;
            dp[i] = dp[s.top()-1] + (i-s.top()+1) ;
            if(dp[i]>maxi)
            {
                maxi = dp[i] ;
                cnt = 1 ;
            }
            else if(dp[i] == maxi)
                cnt++ ;
            s.pop() ;
        }
    }
    cout << maxi << " " << max(cnt,1LL) ;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int tt = 1;
	//cin >> tt ;
	while(tt--)
	{
		solve() ;
	}
}