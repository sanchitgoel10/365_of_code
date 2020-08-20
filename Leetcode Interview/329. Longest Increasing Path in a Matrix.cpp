class Solution {
public:
    const int fx[4]={+1,-1,+0,+0};
    const int fy[4]={+0,+0,+1,-1};
    
    int dfs(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp,int n,int m){
        if(dp[i][j]!=0)return dp[i][j];
        int ans=1;
        for(int d=0;d<4;d++){
            int x=i+fx[d];
            int y=j+fy[d];
            if(x>=0&&x<n&&y>=0&&y<m&&mat[x][y]>mat[i][j]){
                ans=max(ans,1+dfs(x,y,mat,dp,n,m));
            }
        }
        return dp[i][j]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(i,j,matrix,dp,n,m));
            }
        }
        return ans;
    }
};