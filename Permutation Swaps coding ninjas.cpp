/*
BOTH Solution are nice parent wala bhi mene kara hai submit ye bhi
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
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)
vec p(100000);
vec q(100000);

bool bfscheck(vec adj[],int n,bool*visited,int sv){
    
    set<int> pc;
    set<int> qc;
    queue<int> Q;
    Q.push(sv);
    pc.insert(p[sv]);
    qc.insert(q[sv]);
    visited[sv]=1;
    
    while(!Q.empty()){
        int curr=Q.front();
        Q.pop();
        for(auto i:adj[curr]){
            if(!visited[i]){
                visited[i]=1;
                Q.push(i);
                pc.insert(p[i]);
                qc.insert(q[i]);
            }
        }
    }
    
    if(pc==qc)return true;
    return false;
    
}

void solve(vec adj[],int n){
    bool *visited = new bool[n];
    For(i,0,n)visited[i]=0;
    int flag=0;
    For(i,0,n){
        if(!visited[i]){
            if(bfscheck(adj,n,visited,i)==false){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}

int32_t main(){
	FastRead;
	int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        For(i,0,n)cin>>p[i];
        For(i,0,n)cin>>q[i];
        int i1,i2;
        vector<int> adj[n];
        while(m--){
            cin>>i1>>i2;
            i1--;
            i2--;
            adj[i1].pb(i2);
            adj[i2].pb(i1);
        }
        solve(adj,n);
        
    }
	return 0;
}

