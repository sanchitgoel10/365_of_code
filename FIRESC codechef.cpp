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

int bfs(vector<int> adj[],int n,bool*visited,int sv){
    int ans=0;
    queue<int> q;
    q.push(sv);
    ans++;
    visited[sv]=1;
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i:adj[curr]){
            if(!visited[i]){
                ans++;
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return ans;
}

void solve(vector<int> adj[],int n){
    
    bool *visited = new bool[n];
    For(i,0,n)visited[i]=0;
    int captain=1;
    int count=0;
    For(i,0,n){
        if(visited[i]==0){
            captain*=bfs(adj,n,visited,i);
            captain%=mod;
            count++;
        }
    }
    cout<<count<<" "<<captain<<endl;
}

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n];
        int u,v;
        For(i,0,m){
            cin>>u>>v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        solve(adj,n);
    }
	return 0;
}

