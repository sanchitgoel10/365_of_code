#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
//#define int long long int
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
    int x;
    stack<int> s;
    For(i,0,n){
        cin>>x;
        if(!s.empty() && s.top()>0 && x<0){ //conditions left ro right check hoti hai
            bool flag=1;                     // yaha agar !s.empty wali cond last me dalega to error a jayegi
            while(!s.empty() && s.top()>0 && x<0){
                if(abs(x)==abs(s.top())){
                    s.pop();
                    flag=0;
                    break;
                }else if(abs(x)>abs(s.top())){
                    s.pop();
                }else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                s.push(x);
            }
        }else{
            s.push(x);
        }
    }
    vec v;
    while(!s.empty()){
        v.pb(s.top());
        s.pop();
    }
    reverse(v.begin(),v.end());

    for(auto i:v)cout<<i<<" ";
	return 0;
}

