#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        int x;
        pqr minheap;
        For(i,0,n){
            cin>>x;
            if(i<k-1){
                minheap.push(x);
                cout<<-1<<" ";
            }else if(i==k-1){
                minheap.push(x);
                cout<<minheap.top()<<" ";
            }else{
                if(x>minheap.top()){
                    minheap.pop();
                    minheap.push(x);
                }
                cout<<minheap.top()<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}

