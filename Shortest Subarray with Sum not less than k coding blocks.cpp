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

int solve(int*arr,int n,int x){
	int s=0,e=0;
	int minl=INT_MAX;
	int curr_sum=0;
	while(e<n){
		while(curr_sum<x&&e<n){     //making a subarray of sum>=x 
			if(curr_sum<=0&&x>0){     //ignoring negative subarrays 
				s=e;
				curr_sum=0;
			}
			curr_sum+=arr[e];
			e++;
		}
		while(curr_sum>=x&&s<n){    //start ko aage karke dekh rahe hai aur kam ho sakti hai kya length
			if(e-s<minl)minl=e-s;
			curr_sum-=arr[s];
			s++;
		}
	}
	if(minl==INT_MAX)return -1;
	return minl;
}

int32_t main(){
	FastRead;
	int n;
	cin>>n;
	int*arr = new int[n];
	For(i,0,n)cin>>arr[i];
	int k;
	cin>>k;
	cout<<solve(arr,n,k)<<endl;
	return 0;
}

