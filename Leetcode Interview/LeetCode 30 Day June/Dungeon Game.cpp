class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        vector<vector<int>> dp(dun);
        int n=dun.size();
        int m=dun[0].size();
        dp[n-1][m-1]=1;
        for(int i=m-2;i>=0;i--){
            dp[n-1][i]=max(dp[n-1][i+1]-dun[n-1][i+1],1);
        }
        for(int i=n-2;i>=0;i--){
            dp[i][m-1]=max(dp[i+1][m-1]-dun[i+1][m-1],1);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=max(min(dp[i+1][j]-dun[i+1][j],dp[i][j+1]-dun[i][j+1]),1);
            }
        }
        return max(dp[0][0]-dun[0][0],1);    //start cell pe bhi padhi hai ek value
    }
};