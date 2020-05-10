#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int r=matrix.size();
        int c=matrix[0].size();
        
        
        int**dp = new int*[r];
        for(int i=0;i<r;i++){
            dp[i]= new int[c];
            for(int j=0;j<c;j++){
                dp[i][j]=0;
            }
        }
        int m=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(i==0||j==0){
                    if(matrix[i][j]=='1')dp[i][j]=1;
                    else dp[i][j]=0;
                }else{
                    if(matrix[i][j]=='1'){
                        dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    }else{
                        dp[i][j]=0;
                    }
                }
                //cout<<dp[i][j]<<" ";
                m=max(m,dp[i][j]);
                
            }
            //cout<<endl;
        }
        return m*m;
    }
};