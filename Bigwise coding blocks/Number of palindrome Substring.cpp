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

void solve(string &s){
    int dp[1001][1001]={0};
    int n=s.length();
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int d=2;d<n;d++){
        int i=0,j=d;
        while(j<n){
            if(s[i]==s[j]&&dp[i+1][j-1]){
                dp[i][j]=1;
            }
            i++;j++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j])ans++;
        }
    }
    cout<<ans<<endl;
}

int32_t main(){
	FastRead;
	string s;
    cin>>s;
    solve(s);
	return 0;
}

