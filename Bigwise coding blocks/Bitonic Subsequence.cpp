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

int32_t main(){
	FastRead;
	w(t){
		int n;
		cin>>n;
		int*arr= new int[n];
		For(i,0,n){
			cin>>arr[i];
		}
		int*left=new int[n];
		int*right=new int[n];
		left[0]=1;
		for(int i=1;i<n;i++){
			left[i]=1;
			for(int j=i-1;j>=0;j--){
				if(arr[i]>arr[j]){
					left[i]=max(left[i],1+left[j]);
				}
			}
		}
		right[n-1]=1;
		for(int i=n-2;i>=0;i--){
			right[i]=1;
			for(int j=i+1;j<n;j++){
				if(arr[i]>arr[j]){
					right[i]=max(right[i],1+right[j]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,left[i]+right[i]-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}

