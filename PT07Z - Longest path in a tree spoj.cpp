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

int ans;

int bfs(vec adj[],int n,int ind){
    
    bool*visited=new bool[n];
    For(i,0,n)visited[i]=0;
    int *distance=new int[n];
    For(i,0,n)distance[i]=0;
    visited[ind]=1;
    queue<int> q;
    q.push(ind);
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i:adj[curr]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
                distance[i]=distance[curr]+1;
            }
        }
    }
    int maxindex=0;
    ans=distance[0];
    For(i,1,n){
        if(distance[i]>distance[maxindex]){
            maxindex=i;
            ans=distance[i];
        }
    }
    
    return maxindex;
}

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    vec adj[n];
    int u,v;
    int m=n-1;
    while(m--){
    cin>>u>>v;
    u--;v--;
    adj[u].pb(v);
    adj[v].pb(u);
    }
    int firstbfs=bfs(adj,n,0);        //DUAL BFS CALCULTES THE MAX DITANCE BETWEEN PAIRS IN GRAPH
    int secondbfs=bfs(adj,n,firstbfs);  //CONCEPT HAI BETA
    cout<<ans<<endl;
	return 0;
}

