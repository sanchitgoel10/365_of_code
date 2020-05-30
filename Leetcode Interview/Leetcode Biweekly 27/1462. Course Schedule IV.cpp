class Solution {
public:
    
    bool haspath(int s,int v,vector<vector<int>>&adj,int n){
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(s);
        vis[s]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                if(i==v)return 1;
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return 0;
        
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool> ans;
        if(pre.size()==0){
            int x=queries.size();
            vector<bool> a(x,0);
            return a;
        }
        
        vector<vector<int>> adj(n,vector<int>());
        for(auto i:pre){
            adj[i[0]].push_back(i[1]);
        }
        for(auto i:queries){
            if(haspath(i[0],i[1],adj,n))ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};