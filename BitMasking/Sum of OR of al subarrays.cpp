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



/*Observe here that if a bit is being set by an element of the array 
then all subarray having that element will have that bit set. Therefore
 when we calculate sum of all subarrays having that number, we can directly
  multiply number of subarrays by the value that bit is making.
Now, to do this an easy way will be to calculate the number of subarrays
 for which a bit is not set and subtract it from the total number of subarrays.

*/


int sumofor(int*arr,int n,int maxele){
	int totalsubarr=(n*(n+1))/2;
	int msb=log2(maxele);      //getting most significant bit 
	int ans=0;
	for(int i=0;i<=msb;i++){
		vec v;
		int mask=1<<i;
		for(int j=0;j<n;j++){      //for every bit position adding to vec index of numbers with off bit at that position
			if((arr[j]&mask)==0){
				v.pb(j);
			}
		}
		
		int cntsubarr=0;       //number of sub array with elements in v 
		int cnt=1;
		for(int j=1;j<v.size();j++){
			if(v[j]==v[j-1]+1){
				cnt++;
			}else{
				cntsubarr+=(cnt*(cnt+1))/2;
				cnt=1;
			}
		}
		cntsubarr+=(cnt*(cnt+1))/2;

		if(v.size()==0)cntsubarr=0;

		int subarrI=totalsubarr-cntsubarr;   //cntsubarr will not contribute at this bit position
		ans+=(subarrI*(1<<i));
	}
	return ans;
}

int32_t main(){
	FastRead;
	int n;
	cin>>n;
	int*arr = new int[n];
	int maxele=-1;
	For(i,0,n){
		cin>>arr[i];
		maxele=max(maxele,arr[i]);
	}
	cout<<sumofor(arr,n,maxele)<<endl;
	return 0;
}

