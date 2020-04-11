#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        vector<pii> p(n);
        For(i,0,n){
            cin>>p[i].ff;
            p[i].ss=i;
            arr[i]=p[i].ff;
        }
        sort(p.begin(),p.end(),sortinrev);     //sorting planet acc to population in dec order
        
        vector<int> adj[n];
        int v,u;
        For(i,0,n-1){              //making graph of all roots
            cin>>v>>u;
            adj[u-1].push_back(v-1); 
            adj[v-1].push_back(u-1); 
        }
        
        For(i,0,n){
            int x=0;
            int flag=0;
            for(auto j:p){         //iterating on reverse sorted array and checking if that planet can be the best
                if(find(adj[i].begin(),adj[i].end(),j.ss)==adj[i].end() && j.ss!=i){    //1st cond=should not be adjacent
                    cout<<j.ss+1<<" ";                                                  //2nd cond=not the planet itself
                    break;
                }
            }
        }
        cout<<endl;
        
    }
	return 0;
}

