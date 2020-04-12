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

bool sieve[10001];
int cnt[10001];

void pre(){
    
    For(i,0,10001){
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=10000;i++){
        if(sieve[i]){
            for(int j=i*i;j<=10000;j+=i){
                sieve[j]=0;
            }
        }
    }
}

void pre1(){
    For(i,0,10001){
        cnt[i]=0;
    }
    for(int i=0;i<=10000;i++){          //for evry prime number comb increment the solution
        if(sieve[i]){
            for(int j=0;j<=10000;j++){
                if(sieve[j]){
                    if(i+2*j>10000)break;
                    cnt[i+2*j]++;
                }
            }
        }
    }
}


int32_t main(){
    FastRead;
    int t;
    cin>>t;
    pre();
    pre1();
    while(t--){
        int n;
        cin>>n;
        cout<<cnt[n]<<endl;
    }
    return 0;
}

