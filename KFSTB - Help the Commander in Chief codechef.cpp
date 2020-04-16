// C++ program for Number of paths 
// from one vertex to another vertex 
// in a Directed Acyclic Graph 
#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 1000005 
#define vec vector<int>
#define mod 1000000007
// function to add edge in graph 
void add_edge(int a, int b, int fre[],vec v[]) 
{ 
	// there is path from a to b. 
	v[a].push_back(b); 
	fre[b]++; 
} 
 
// function to make topological sorting 
vector<int> topological_sorting(int fre[], int n, vec v[]) 
{ 
	queue<int> q; 
 
	// insert all vertices which 
	// don't have any parent. 
	for (int i = 0; i < n; i++) 
		if (!fre[i]) 
			q.push(i); 
 
	vector<int> l; 
 
	// using kahn's algorithm 
	// for topological sorting 
	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 
 
		// insert front element of queue to vector 
		l.push_back(u); 
 
		// go through all it's childs 
		for (int i = 0; i < v[u].size(); i++) { 
			fre[v[u][i]]--; 
 
			// whenever the freqency is zero then add 
			// this vertex to queue. 
			if (!fre[v[u][i]]) 
				q.push(v[u][i]); 
		} 
	} 
	return l; 
} 
 
// Function that returns the number of paths 
int numberofPaths(int source, int destination, int n, int fre[],vec v[]) 
{ 
 
// make topological sorting 
	vector<int> s = topological_sorting(fre, n, v); 
 
	// to store required answer. 
	int dp[n] = { 0 }; 
 
	// answer from destination 
	// to destination is 1. 
	dp[destination] = 1; 
 
	// traverse in reverse order 
	for (int i = s.size() - 1; i >= 0; i--) { 
		for (int j = 0; j < v[s[i]].size(); j++) { 
			dp[s[i]] = (dp[s[i]]%mod +  dp[v[s[i]][j]]%mod)%mod; 
		} 
	} 
 
	return dp[source]; 
} 
 
// Driver code 
int main() 
{ 
 
	int t;
	cin>>t;
	while(t--){
	    int n,m,s,d;
	    cin>>n>>m>>s>>d;
	    vec v[n];
	    s--;
	    d--;
	    int fre[n] = { 0 };
	    int u,x;
	    while(m--){
	        cin>>u>>x;
	        u--;
	        x--;
	        add_edge(u,x,fre,v);
	    }
	    cout<<numberofPaths(s,d,n,fre,v)<<endl;
	}
} 