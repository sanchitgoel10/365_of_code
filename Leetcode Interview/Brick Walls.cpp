class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edges;
        auto minBricks = wall.size();
        
        for(auto row: wall){
            for(int i = 0, width = 0; i <row.size()-1; i++){
                width += row[i];
                edges[width] += 1;
            }
        }
        
        for(auto edge: edges) minBricks = min(minBricks, wall.size() - edge.second);
        return minBricks;
    }
};