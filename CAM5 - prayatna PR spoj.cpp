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

void dfs(vec adj[],int n,bool*visited,int sv){
    visited[sv]=1;
    for(auto i:adj[sv]){
        if(!visited[i]){
            dfs(adj,n,visited,i);
        }
    }
}

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vec adj[n];
	    int m;
	    cin>>m;
	    int u,v;
	    while(m--){
	        cin>>u>>v;
	        adj[u].pb(v);
	        adj[v].pb(u);
	    }
	    int count=0;
	    bool *visited=new bool[n];
	    For(i,0,n)visited[i]=0;
	    For(i,0,n){
	        if(!visited[i]){
	            count++;
	            dfs(adj,n,visited,i);
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

