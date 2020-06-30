class Solution {
public:
    vector<vector<int>> children;
    int dfs(int node,vector<int>& informTime)
    {
        int time=0;
        for(int &n:children[node])
            time=max(time,dfs(n,informTime));		//Get the max time to reach the last child under the current node.
        return informTime[node]+time;				//Return the time required for this employee to inform + the time for it's children to inform all under them
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        children.resize(n);
        for(int i=0;i<manager.size();i++)				//Create Adjacency list
            if(manager[i]!=-1)
                children[manager[i]].push_back(i);
        return dfs(headID,informTime);
    }
};