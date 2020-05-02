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

class node{
	public:
	string s;
	int mask;
	int p;
};

int solve(int msk,int pos,int n,int**dp,node*arr){
	if(pos==n)return INT_MAX;
	if(dp[msk][pos]!=0 || msk==7)return dp[msk][pos];

	int maskpos=arr[pos].mask;
	int currprice=arr[pos].p;
	dp[msk][pos]=min(solve(msk,pos+1,n,dp,arr),currprice+solve(msk|maskpos,pos+1,n,dp,arr));
	return dp[msk][pos];
}

int32_t main(){
	FastRead;
	int n;
	cin>>n;
	node*arr = new node[n];

	For(i,0,n){
		cin>>arr[i].s;
		int a=0,b=0,c=0;
		for(auto i:arr[i].s){
			if(i=='A'){
				a=1;
			}else if(i=='B'){
				b=1;
			}else{
				c=1;
			}
		}
		arr[i].mask=0;
		if(a){
			arr[i].mask+=1;
		}
		if(b){
			arr[i].mask+=2;
		}
		if(c){
			arr[i].mask+=4;
		}
	}
	For(i,0,n){
		cin>>arr[i].p;
	}
	
	int**dp = new int*[8];
	For(i,0,8){
		dp[i]=new int[n];
		For(j,0,n)dp[i][j]=0;
	}
	cout<<solve(0,0,n,dp,arr)<<endl;
	return 0;
}

