#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

int sieve[100001];
int ans[6][100001];

void pre(){
    
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i<=100000;i++){         //ye loop isliye pura chala rahe hai kyuki har prime pe 1 to rakhna hai hi
        if(sieve[i]==0){
            for(int j=i;j<=100000;j+=i){
                sieve[j]++;
            }
        }
    }
    For(i,1,6){
        For(j,2,100001){
            if(sieve[j]==i)ans[i][j]=ans[i][j-1]+1;
            else ans[i][j]=ans[i][j-1];
        }
    }
}

int32_t main(){
    FastRead;
    pre();
    
    int t;
    cin>>t;
    while(t--){
        int a,b,k;
        cin>>a>>b>>k;
        cout<<ans[k][b]-ans[k][a-1]<<endl;
    }
    return 0;
}

