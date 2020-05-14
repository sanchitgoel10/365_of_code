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

int*arr;
int dp[1001][1001];

int solve(int left,int right){
    if(right-left<=1)return 0;

    if(dp[left][right]!=-1)return dp[left][right];

    int ans=0;
    for(int pivot=left+1;pivot<right;pivot++){   //this means the pivot book is included last
        ans=max(ans,arr[left]*arr[pivot]*arr[right]+solve(left,pivot)+solve(pivot,right));
    }
    dp[left][right]=ans;
    return dp[left][right];
}

int32_t main(){
	FastRead;
	memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    arr = new int[n+2];
    arr[0]=1;
    arr[n+1]=1;
    For(i,1,n+1){
        cin>>arr[i];
    }
    cout<<solve(0,n+1)<<endl;
	return 0;
}

