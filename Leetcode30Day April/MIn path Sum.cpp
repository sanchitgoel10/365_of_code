#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0)return 0;
        
        int r=grid.size();
        int c=grid[0].size();
        
        int**dp = new int*[r];
        for(int i=0;i<r;i++){
            dp[i]= new int[c];
            for(int j=0;j<c;j++){
                dp[i][j]=grid[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i>0&&j>0){
                    dp[i][j]+=min(dp[i-1][j],dp[i][j-1]);
                }else if(i>0){
                    dp[i][j]+=dp[i-1][j];
                }else if(j>0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
        
        return dp[r-1][c-1];
    }
};