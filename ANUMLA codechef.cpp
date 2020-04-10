#include<bits/stdc++.h>
using namespace std;
typedef int ll;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e9;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert

ll n;
ll a[1<<16];
ll ans[1<<16];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input00.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=0;i<(1<<n);i++)
            cin>>a[i];
        
        sort(a,a+(1<<n));
        map<ll,ll> MAP;
        ll pos=0;
        vector<ll> SET;                        //stores sum of all subsets upto that index
        for(ll i=1;i<(1<<n);i++){
            if(MAP.begin()->ff == a[i]){       //not a new number just sum of sum subset
                MAP.begin()->ss--;
                if(MAP.begin()->ss==0)         
                    MAP.erase(MAP.begin());
            }
            else{                             //new number
                ll no = a[i];
                ans[pos++] = no;
                vector<ll> tmp;
                for(auto it : SET){          // make all possible sum of subset with earlier number
                    tmp.pb(it + no);
                    MAP[it+no]++;
                }
                SET.pb(no);
                for(auto it : tmp)
                    SET.pb(it);
            }
        }

        for(ll i=0;i<n;i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}