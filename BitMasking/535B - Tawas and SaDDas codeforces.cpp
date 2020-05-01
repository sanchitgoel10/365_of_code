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
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

//DRY run karke hi feel ayegi

int32_t main(){
	FastRead;
	string s;
	cin>>s;
	int ans=0;
	int d=s.length();  //number of digits
	For(i,0,d){
	    int p=d-i-1;   //power of the digit 
	    if(s[i]=='7')  //7 hai matlan 4 aur 7 dono the 
	        ans+=(1<<p);
	}
	For(i,1,d){         //total number of numbers less than it but of less digits
	    ans+=(1<<i);
	}
	cout<<ans+1<<endl;   //1 based indexing
	return 0;
}

