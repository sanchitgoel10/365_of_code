#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(n==0||m==0)return 0;
        ll**dp = new ll*[n];
        for(int i=0;i<n;i++){
            dp[i]=new ll[m];
        }
        if(obstacleGrid[n-1][m-1]==0)dp[n-1][m-1]=1;
        else{
            return 0;
        }
        
        for(int j=m-2;j>=0;j--){
            if(obstacleGrid[n-1][j]==0)
                dp[n-1][j]=dp[n-1][j+1];
            else dp[n-1][j]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(obstacleGrid[i][m-1]==0)
                dp[i][m-1]=dp[i+1][m-1];
            else dp[i][m-1]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                else dp[i][j]=0;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};