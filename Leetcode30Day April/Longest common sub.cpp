#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int r=text1.length();
        int c=text2.length();
        int**dp = new int*[r+1];
        for(int i=0;i<=r;i++){
            dp[i]= new int[c+1];
            for(int j=0;j<=c;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                }
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[r][c];
    }
};