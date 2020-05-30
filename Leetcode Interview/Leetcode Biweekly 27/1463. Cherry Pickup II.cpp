class Solution {
public: 
    int dp[70][70][70];    //dp[row][column1][column2]
    
    int dfs(vector<vector<int>>&grid,int n,int m,int r,int c1,int c2){
        if(r==n)return 0;            //row exceeds limit
        int ans=0;
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nc1=c1+i;
                int nc2=c2+j;
                if(nc1>=0&&nc1<m&&nc2>=0&&nc2<m){
                    ans=max(ans,dfs(grid,n,m,r+1,nc1,nc2));
                }
            }
        }
        
        int curr_cherries = c1==c2?grid[r][c1]:grid[r][c1]+grid[r][c2];        //both robot on same cell
        return dp[r][c1][c2]=ans+curr_cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size(),m=grid[0].size();
        
        return dfs(grid,n,m,0,0,m-1);
    }
};