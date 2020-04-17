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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int ans;
char g[1001][1001];
int visited[1001][1001];
int dist[1001][1001];


//again dual bfs


bool ing(int x,int y,int c,int r){
    if(x>-0&&x<r&&y>=0&&y<c)return 1;
    return 0;
}

pii bfs(pii s,int c,int r){
    pii e;
    queue<pii> q;
    q.push(s);
    visited[s.ff][s.ss]=1;
    int len=-1;
    while(!q.empty()){
        pii curr=q.front(),next;
        q.pop();
        for(int i=0;i<4;i++){
            next.ff=curr.ff+dx[i];
            next.ss=curr.ss+dy[i];
            if(ing(next.ff,next.ss,c,r)){
                if(!visited[next.ff][next.ss]&&g[next.ff][next.ss]=='.'){
                    visited[next.ff][next.ss]=1;
                    dist[next.ff][next.ss]=dist[curr.ff][curr.ss]+1;
                    if(dist[next.ff][next.ss]>len){
                        len=dist[next.ff][next.ss];
                        ans=len;
                        e=next;
                    }
                    q.push(next);
                }
            }
        }
    }
    return e;
}

void solve(int c,int r){
    For(i,0,1001){
        For(j,0,1001){
            visited[i][j]=0;
        }
    }
    
    pii st,diameterend;
    int flag=0;
    For(i,0,r){
        For(j,0,c){
            if(g[i][j]=='.'){
                st=mp(i,j);
                flag=1;
                break;
            }
            if(flag)break;
        }
    }
    dist[st.ff][st.ss]=0;
    diameterend=bfs(st,c,r);
    
    For(i,0,1001){
        For(j,0,1001){
            visited[i][j]=0;
        }
    }
    dist[diameterend.ff][diameterend.ss]=0;
    bfs(diameterend,c,r);
}

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    ans=0;
	    int c,r;
	    cin>>c>>r;
	    For(i,0,r){
	        For(j,0,c){
	            cin>>g[i][j];
	        }
	    }
	    solve(c,r);
	    cout<<"Maximum rope length is "<<ans<<"."<<endl;
	}
	return 0;
}

