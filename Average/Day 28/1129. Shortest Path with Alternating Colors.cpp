class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<pair<int,bool>> adj[n];        //from - to,color
        for(auto i:red_edges){
            adj[i[0]].push_back({i[1],0});   //0 means red
        }
        for(auto i:blue_edges){
            adj[i[0]].push_back({i[1],1}); //1 means blue
        }
        vector<vector<int>> vCost(n, vector<int>(2,-1));     //vcost for both types of path ending on blue/red
        queue<pair<int,bool>> q;
        q.push({0,0});        //at zero both path posssible
        q.push({0,1});
        vCost[0]={0,0};
        while(!q.empty()){
            auto [i,c1]=q.front();
            q.pop();
            for(auto [j,c2]:adj[i]){
                
                if(vCost[j][c2]!=-1||c1==c2)continue;  //already visited or same color
                
                vCost[j][c2] = 1 + vCost[i][c1];     
                q.push({j,c2});           //push this 
            }
        }
        vector<int> ans;
        for(auto &v:vCost){
            sort(v.begin(),v.end());         //shorter of the two alternatives
            ans.push_back(v[0]!=-1?v[0]:v[1]);
        }
        return ans;
    }
};