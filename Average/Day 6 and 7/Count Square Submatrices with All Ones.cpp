/*dp[i][j] means the size of biggest square with A[i][j] as bottom-right corner.
dp[i][j] also means the number of squares with A[i][j] as bottom-right corner.

If A[i][j] == 0, no possible square.
If A[i][j] == 1,
we compare the size of square dp[i-1][j-1], dp[i-1][j] and dp[i][j-1].
min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 is the maximum size of square that we can find.


This explanation is not of the solution below but the old common prob can be used to solve the same
*/

class Solution {
public:
    int dp[302][302];
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& matrix){
        if(i>=n||j>=m)return 0;
        if(matrix[i][j]==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int p=dfs(i+1,j,matrix);
        int q=dfs(i,j+1,matrix);
        int r=dfs(i+1,j+1,matrix);
        
        return dp[i][j]=1+min(p,min(q,r));
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        n=matrix.size();
        m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]){
                    ans+=dfs(i,j,matrix);
                }
            }
        }
        return ans;
        
    }
};