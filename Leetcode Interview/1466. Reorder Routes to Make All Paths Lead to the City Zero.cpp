class Solution {
public:
    
    void dfs(int node,unordered_set<int>&visited,unordered_map<int,vector<pair<int,int>>>&m,int&ans){
        if(visited.find(node)!=visited.end())return ;
        visited.insert(node);
        for(auto i:m[node]){
            if(visited.find(i.first)==visited.end()&&i.second==0)ans++;    //koi ek node hai jo ulti direction me hai
            dfs(i.first,visited,m,ans);
        }
        
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto c:connections){
            m[c[0]].push_back({c[1],0});               //o and 1 signifies direction 
            m[c[1]].push_back({c[0],1});
        }
        unordered_set<int> visited;
        int ans=0;
        dfs(0,visited,m,ans);
        return ans;
    }
};