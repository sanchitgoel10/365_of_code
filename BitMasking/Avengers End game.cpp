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


/*
Well here’s something :
Number of numbers in the range [X, Y] divisible by Z is
(Y/Z) - (X/Z) , if X%Z != 0
(Y/Z) - (X/Z) + 1 , if X%Z == 0

You’ll have to modify the code. It counts the same number more than once.
Say N = 10 :
case 2 : 2, 4, 6, 8, 10
case 3 : 3, 6, 9
case 5 : 5, 10
case 7 : 7
So, you see it’ll output 5+3+2+1 = 11, because 6 and 10 are counted twice.
So what you need to do is count only those numbers which are not already considered.

In order to exclude 6 and 10 in the example I gave earlier, 
let the number of numbers divisible by 2 be c1 and that of 3 be c2.
 Now find the number of numbers that are divisible by 2*3 i.e. 6 (say c3) 
 and put c1 + c2 - c3 in the final result. This was just for 2 and 3, 
 you need to do this for the whole array of {2, 3, 5, 7, 11, 13, 17, 19}.
*/

int prime[8]={2, 3, 5, 7, 11, 13, 17, 19};

int32_t main(){
	FastRead;
	int n;
	w(t){
		cin>>n;
		int ans=0;
		for(int i=0;i<8;i++){
			ans+=(n/prime[i]-1/prime[i]);
		}
		for(int i=0;i<7;i++){
			for(int j=i+1;j<8;j++){
				int exc=prime[i]*prime[j];
				ans-=(n/exc-1/exc);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

