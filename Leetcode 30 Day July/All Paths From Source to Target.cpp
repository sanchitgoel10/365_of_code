class Solution {
public:
    
    void dfs(vector<vector<int>> &paths,vector<int> path,vector<vector<int>> &g,int i,int l){   //path vector is passed by value
        path.push_back(i);
        if(i==l){
            paths.push_back(path);
            return;
        }
        for(auto n:g[i]){
            dfs(paths,path,g,n,l);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        int n=graph.size();
        if(n==0)return paths;
        dfs(paths,path,graph,0,n-1);
        return paths;
    }
};

//Path vector passed by refference 
 void dfs(vector<vector<int>>& g, vector<vector<int>>& res, vector<int>& path, int cur) {
        path.push_back(cur);
        if (cur == g.size() - 1)
            res.push_back(path);
        else for (auto it: g[cur])
            dfs(g, res, path, it);
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(g, paths, path, 0);
        return paths;
    }