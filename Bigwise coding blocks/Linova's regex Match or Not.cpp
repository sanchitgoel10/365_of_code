#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define set set<int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)
#define w(t) int t;cin>>t;while(t--)

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

// class node{
//     public:
//     int data;
//     node*left;
//     node*right;
//     node(int d):data(d),left(NULL),right(NULL){
//     }
// };

//VIDEO DEKH YOUTUBE PAR WEEK4

void solve(string &s,string &p){
    bool dp[1001][1001]={0};
    dp[0][0]=1;
    int n=s.length();
    int m=p.length();

    For(i,1,m+1){
        if(p[i-1]=='*'){
            dp[0][i]=dp[0][i-2];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==p[j-1]||p[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                if(p[j-2]==s[i-1]||p[j-2]=='.'){
                    dp[i][j]=dp[i][j]||dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int32_t main(){
	FastRead;
	string s,p;
    cin>>s>>p;
    solve(s,p);
	return 0;
}

