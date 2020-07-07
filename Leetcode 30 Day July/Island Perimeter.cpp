/*The idea is each time, we encounter a boundary, count++;
Iterative:
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        const int fx[4]={+1,-1,+0,+0};
        const int fy[4]={+0,+0,+1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    for(int d=0;d<4;d++){
                        int x=i+fx[d];
                        int y=j+fy[d];
                        if(x<0||y<0||x>=n||y>=m||grid[x][y]==0){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//MAths
/*
the description of this problem implies there may be an "pattern" in calculating the perimeter of the islands.
and the pattern is islands * 4 - neighbours * 2, since every adjacent islands made two sides disappeared(as picture below).
+--+     +--+                   +--+--+
|  |  +  |  |          ->       |     |
+--+     +--+                   +--+--+
*/
int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }