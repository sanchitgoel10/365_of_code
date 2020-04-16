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

//first find all the 4 digit prime no. , make the adjacency list by adding the numbers if they differ by one digit and then do the bfs for getting the //shortest path(minimum cost)

int sieve[10000];
vec prime;

bool diff1(int a,int b){           //Function to check if numbers differ by just one digit
	int diff=0;
	while(a){
		if(a%10!=b%10)diff++;
		a/=10;
		b/=10;
	}
	if(diff>1)return false;
	return true;
}

void pre(){
    
    For(i,0,10001){
        sieve[i]=1;
    }
    sieve[0]=0;
    sieve[1]=0;
    for(int i=2;i*i<=10000;i++){
        if(sieve[i]){
            for(int j=i*i;j<=10000;j+=i){
                sieve[j]=0;
            }
        }
    }
    For(i,1000,10000){                   //storing all prime numbers between range
        if(i>=1000&&i<=9999){
            if(sieve[i]){
                prime.pb(i);
            }
        }
    }
}

int bfs(vec adj[],int n,int source,int dest){        //bfs for shortest path
    
    int s=find(prime.begin(),prime.end(),source)-prime.begin();     //index of source
    int d=find(prime.begin(),prime.end(),dest)-prime.begin();
    
    bool*visited=new bool[n];
    int *dist=new int[n];
    For(i,0,n)visited[i]=0,dist[i]=INT_MAX;
    
    queue<int> q;
    q.push(s);
    visited[s]=1;
    
    dist[s]=0;
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        
        for(auto i:adj[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
                dist[i]=dist[curr]+1;
            }
            if(i==d){
                break;
            }
        }
    }
    return dist[d];
}

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	pre();
	int n=prime.size();
	vec adj[n];
	For(i,0,n){       //on all prime pairs 
	    For(j,0,n){
	        int x=prime[i];
	        int y=prime[j];
	        if(diff1(x,y)){    //if number differ by one add on graph
	            adj[i].pb(j);
	            adj[j].pb(i);
	        }
	    }
	}
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int ans=bfs(adj,n,a,b);
	    cout<<ans<<endl;
	}
	return 0;
}

