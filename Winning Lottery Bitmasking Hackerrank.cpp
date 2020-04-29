The idea is to represent each number as the mask of 10 bits such that if it contains digit i at least once then ith bit will be set in the mask.
For example,
let n = 4556120 then 0th, 1st, 2nd, 4th, 5th, 6th bits will be set in mask.
Thus, mask = (0001110111)2 = (119)10
Now, for every mask m from 0 to 2^10 – 1, we will store the count of the number of numbers having the mask of their number equals to m.

A pair of numbers will have all the digit from 0 to 9 if every bits from 0 to 9 is set in the bitwise OR of maskof both the number, i.e if it’s equal to (1111111111)2</sub) = (1023)10

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

int32_t main(){
    FastRead;
    int n;
    cin>>n;
    string x;
    int cnt[1<<10];
    For(i,0,1<<10){
        cnt[i]=0;
    }
    For(i,0,n){
        cin>>x;
        int mask=0;
        for(auto j:x){
            mask|=(1<<(j-'0'));
        }
        cnt[mask]++;
    }
    int ans=0;
    int fullmask=(1<<10)-1;
    for(int i=0;i<1<<10;i++){
        for(int j=i+1;j<1<<10;j++){
            if((j|i)==fullmask){
                ans+=(cnt[i]*cnt[j]);
            }
        }
    }
    //now case where all digits already there
    ans+=(cnt[fullmask]*(cnt[fullmask]-1))/2;
    cout<<ans;
    
    return 0;
}

