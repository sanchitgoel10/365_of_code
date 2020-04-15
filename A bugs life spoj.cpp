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

bool bipart(vec adj[],int n){
    bool*visited=new bool[n];
    For(i,0,n)visited[i]=0;
    
    For(i,0,n){
        if(!visited[i]){
            unordered_set<int> sets[2];
            queue<int> q;
            q.push(i);
            visited[i]=1;
            sets[0].insert(i);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                int currset=sets[0].count(curr)>0?0:1;
                for(auto j:adj[curr]){
                    if(sets[0].count(j)==0&&sets[1].count(j)==0){
                        visited[j]=1;
                        q.push(j);
                        sets[1-currset].insert(j);
                    }else if(sets[currset].count(j)>0){
                        return false;
                    }
                }
            }
        }
    }
    return true;
    
}

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    int tc=1;
    while(t--){
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
      bool ans=bipart(adj,n);
      if(ans){
          cout<<"Scenario #"<<tc<<":"<<endl;
          cout<<"No suspicious bugs found!"<<endl;
      }else{
         cout<<"Scenario #"<<tc<<":"<<endl;
         cout<<"Suspicious bugs found!"<<endl; 
      }
      tc++;
    }
	return 0;
}

