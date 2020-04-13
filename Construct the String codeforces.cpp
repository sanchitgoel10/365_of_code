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

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    int n,a,b;
	    cin>>n>>a>>b;
	    string ans="";
	    string add="";
	    char beg='a';
	    For(i,0,b){
	        add+=beg;
	        beg++;
	    }
	    For(i,0,n){
	        int ind=i%b;
	        ans+=add[ind];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

