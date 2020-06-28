class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q,qtemp;
        int steps=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    q.push({i-1,j});
                    q.push({i,j-1});
                    q.push({i+1,j});
                    q.push({i,j+1});
                }
            }
        }
        while(!q.empty()){
            ++steps;
            while(!q.empty()){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i>=0&&i<=grid.size()&&j>=0&&grid[i].size()&&grid[i][j]==0){
                    grid[i][j]=steps;
                    qtemp.push({i+1,j});
                    qtemp.push({i,j-1});
                    qtemp.push({i-1,j});
                    qtemp.push({i,j+1});
                }
            }
            swap(q,qtemp);
        }
        return steps==1?-1:steps-1;
    }
};