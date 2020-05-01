#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long 
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
/*
We can see that first bit from L to R either changes from 0 to 1 or it stays 1 i.e.
if we take the XOR of any two numbers for maximum value their first bit will be fixed which 
will be same as first bit of XOR of L and R itself.
After observing the technique to get first bit, we can see that if we XOR L and R, 
the most significant bit of this XOR will tell us the maximum value we can achieve i.e.
let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get
is 1111 because from L to R we have all possible combination of xxx and 
it is always possible to choose these bits in such a way from two
numbers such that their XOR becomes all 1
*/


int maximumXOR(int l, int r) {
    int q = l ^ r, a = 1;
    while(q){
        q /= 2;
        a <<= 1;
    }
    return --a;
}

int32_t main(){
	FastRead;
	int l,r;
	cin>>l>>r;
	cout<<maximumXOR(l,r)<<endl;
	return 0;
}

