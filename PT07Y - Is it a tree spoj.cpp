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

//Also alternate approach check connected comp==1 and edges==n-1

int32_t main(){
	FastRead;
	int n,m;
	cin>>n>>m;
	vec adj[n];
	int u,v;
	while(m--){
	    cin>>u>>v;
	    u--;v--;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	bool *visited = new bool[n];
	int *parent = new int[n];
	For(i,0,n){
	    visited[i]=0;
	    parent[i]=-1;
	}
	
	queue<int> q;
	q.push(0);
	visited[0]=1;
	int flag=0;
	while(!q.empty()){
	    int curr=q.front();
	    q.pop();
	    for(auto i:adj[curr]){
	        if(!visited[i]){
	            visited[i]=1;
	            parent[i]=curr;
	            q.push(i);
	        }else{ 
	            if(parent[curr]!=i){          //already visited then it should be parent of that element 
	                flag=1; 
	                break;
	            }
	        }
	        
	    }
	}
	
	For(i,0,n){                    //check connected component==1
	    if(visited[i]==0)flag=1;
	}
	
	if(flag){
	    cout<<"NO"<<endl;
	}else{
	    cout<<"YES"<<endl;
	}
	return 0;
}

