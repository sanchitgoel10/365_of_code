/*
Let us assume that we have a data structure which can give us the next number divisible by p in the range [l r] in O(t) time, t is what we will find out later.

Can you give an estimate of total amortised cost on the total time complexity using the above data structure ?

If we forget that there is any query of type 2, then what will be the total amortised cost ?
As each number is less than 109, in the worst case a number can be divided by p by at most 30 times (when p is 2 and number is 109).
So total time complexity would be O(t) * 30 * N

Now Let us add queries of type 2.
Each number which is replaced will require at most 30 steps to reach 1. So at most M numbers are added.
So total time complexity is O(t) * 30 * (M + N) + Time required to change the data structure for query 2.

Now, if t = O(log N), then we are done.

*/
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

int32_t main(){
	FastRead;
	int n,m;
	cin>>n;
	int arr[n];
	For(i,0,n)cin>>arr[i];
	cin>>m;
	set myset[6];
	For(i,0,n){
	    if(arr[i]%2==0) myset[2].insert(i);
	    if(arr[i]%3==0) myset[3].insert(i);
	    if(arr[i]%5==0) myset[5].insert(i);
	}
	int type,l,r,d,p;
	while(m--){
	    cin>>type;
	    if(type==1){
	        cin>>l>>r>>p;
	        l--;r--;
	        vec del;
	        auto a=lower_bound(myset[p].begin(),myset[p].end(),l);
	        for(auto it=a;it!=myset[p].end();it++){
	            if(*it>r)break;       //since sorted
	            arr[*it]/=p;
	            if(arr[*it]%p){
	                del.pb(*it);
	            }
	        }
	        for(auto i:del){
	            myset[p].erase(i);
	        }
	    }else{
	        cin>>l>>d;
	        l--;
	        if(arr[l]%2==0)myset[2].erase(l);
	        if(arr[l]%3==0)myset[3].erase(l);
	        if(arr[l]%5==0)myset[5].erase(l);
	        
	        arr[l]=d;
	        
	        if(d%2==0) myset[2].insert(l);
	        if(d%3==0) myset[3].insert(l);
	        if(d%5==0) myset[5].insert(l);
	    }
	}
	
	For(i,0,n)cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

