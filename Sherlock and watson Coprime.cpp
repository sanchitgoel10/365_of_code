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
There are 50 numbers in the array, so there can 250 possible subsets, that we need to consider. Of course if we are going to check each of the subsets, one by one checking if that has no co prime pairs, it will take a lot of time. We need to think of something else. When we are doing the above process, we are redoing lots of things. This is where Dynamic Programming comes into picture, to store and resuse the computed information.
Firstly, observe that there are only 15 prime numbers inside the first 50 natural numbers. Any number in the array will have only prime factors among these 15 number. This does mean we can store these as masks (or seive). Lets say we have number 6, with factors 2 and 3. Then we will set the first two bits of the mask. This means that in future, if we want to extend this set (of number 6), then we should avoid taking numbers that have factors of already set bits in this set (here the first two bits).
Okay, so here is the idea then. Firstly compute for each number in the array, the indices of the prime factors. So if number has a factor 2, we will store 1 in the list, if 5 then we will store 3, as 5 is the 3rd prime. Now lets define our DP recurrence. We will maintain a 2D array, dp[index][mask] which says, given a mask mask, what is the largest subset of co primes that can be generated from all the numbers in and after index position. So dp[index][mask] gives the answer to the question, what is the largest subset on and after index. This enalbes us to create a function rec(index, mask) whose initial call as (0, 0) {first 0 says all numbers from 0 and afterwards, second 0 says initally mask is empty} will give us the answer to the problem. There will be two options to consider, weather include the current index to the subset, or dont include it.
Dont include - Simply return rec(index + 1, mask).
Include - Firstly check if the current index is suitable to be included or not. Run a loop and check if mask is set for a position in the prime factor list we created in the beginning for this index. If there is any prime which is already in the mask, we cannot include to simply return the answer to rec(index + 1, mask). Othwerise, this is fit to be included, so tamper the mask to set all the bits for the positions which are prime factors of this number. Then returned value should be 1 + rec(index + 1, newMask). 1 indicates we included this number, and passed the newMask (setting all appropriate bits) and getting answer from rec(index + 1, newMask).
Ofcourse the answer should be the maximum of both the cases and that should be the return value of our call to rec(index, mask).
Finally, a few things worhty to note. We can check if bit is set or not, by using bitwise AND [mask & (1 << primePosition)]. Similarly, we can set a bit by using bitwise OR [mask & (1 << primePosition)]. To avoid recacluation of the same function rec(index, mask), we can maintain a table initialized by -1. Firstly we check if dp[index][mask] is -1 or not. If not we return becuase that has been already calcualted. Othwerwise we calculate as above and also store dp[index][mask], so that we can reuse it later. Complexity ? Because each entry of the table is computed only once, We can make atmost (N * 215) calls to the function. Inside the function we just run a loop for size of prime list for that index which can be atmost 15. Therefore, overall complexity is O(N * 15 * 215). See testers code for neat implementation of the idea.




*/


int sieve[51];
vec primes;

void pre(){
	For(i,0,51){
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=50;i++){
        if(sieve[i]){
            for(int j=i*i;j<=50;j+=i){
                sieve[j]=0;
            }
        }
    }
	For(i,0,51){
		if(sieve[i]){
			primes.pb(i);
		}
	}	
}

int check(int num,int mask){
	int reply=0;
	int flag=0;
	for(int i=0;i<primes.size();i++){
		int p=primes[i];
		if((num%p==0)&&(mask&(1<<i))){
			flag=1;
			break;
		}else if(num%p==0){
			reply|=(1<<i);
		}
	}
	if(flag)return -1;
	return reply;
}

int solve(int mask,int pos,int n,int**dp,int*arr){
	if(pos==n)return 0;
	if(dp[mask][pos]!=-1)return dp[mask][pos];

	int ret=0;
	int num=arr[pos];
	int reply=check(num,mask);
	if(reply!=-1){
		int newmask=reply|mask;
		ret=max(ret,solve(newmask,pos+1,n,dp,arr)+1);
	}
	ret=max(ret,solve(mask,pos+1,n,dp,arr));

	dp[mask][pos]=ret;
	return ret;
}

int32_t main(){
	FastRead;
	pre();
	int n;
	cin>>n;
	int*arr = new int[n];
	For(i,0,n)cin>>arr[i];
	int**dp = new int*[1<<16];
	For(i,0,(1<<16)){
		dp[i]=new int[n];
		For(j,0,n)dp[i][j]=-1;
	}
	cout<<solve(0,0,n,dp,arr)<<endl;
	return 0;
}

