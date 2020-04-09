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
    int t;
    cin>>t;
    while(t--){
        int n,M;
        cin>>n>>M;
        mii m;
        vector<int> a1(n);
        vector<int> a2(M);
        For(i,0,n){
            cin>>a1[i];
            if(m.find(a1[i])==m.end()) m[a1[i]]=1;
            else m[a1[i]]++;
        }
        For(i,0,M)cin>>a2[i];
        vector<int> ans;
        For(i,0,M){
            while(m[a2[i]]!=0){
                ans.pb(a2[i]);
                m[a2[i]]--;
            }
            m.erase(a2[i]);
        }
        for(auto it:m){
            while(m[it.ff]!=0){
                ans.pb(it.ff);
                m[it.ff]--;
            }
        }
        For(i,0,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}

