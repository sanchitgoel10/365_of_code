
/*
As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
Use DFS to determine the number of isolated computer clusters.
*/
class Solution {
public:
    
    void bfs(vector<int>&vis,int i,unordered_map<int,vector<int>>&m){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto n:m[curr]){
                if(vis[n])continue;
                q.push(n);
                vis[n]=1;
            }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int x=connections.size();
        if(x<n-1)return -1;
        unordered_map<int,vector<int>> m;
        for(auto i:connections){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(vis,i,m);
                ans++;
            }
        }
        return ans-1;
    }
};


//UNion find
class Solution {
    vector<int>parent;
    int find(int x) {
        return (parent[x] == x) ? x : find(parent[x]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (n-1 > c) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < c; i++) {
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if (x != y) parent[y] = x;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
    }
};