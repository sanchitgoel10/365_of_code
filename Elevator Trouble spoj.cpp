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

int bfs(vec adj[],int s,int e,int n){
    int dist[n];
    For(i,0,n)dist[i]=-1;
    dist[s]=0;
    queue<int> q;
    bool*visited=new bool[n];
    For(i,0,n)visited[i]=0;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i:adj[curr]){
            if(!visited[i]){
                dist[i]=dist[curr]+1;
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return dist[e];
}

int32_t main(){
	FastRead;
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	s--;g--;
	vec adj[f];
	int l,h;
	For(i,0,f){
	    l=i-d;
	    h=i+u;
	    if(l>=0)adj[i].pb(l);
	    if(h<f)adj[i].pb(h);
	}
	int ans=bfs(adj,s,g,f);
	if(ans==-1)cout<<"use the stairs"<<endl;
	else cout<<ans<<endl;
	return 0;
}

