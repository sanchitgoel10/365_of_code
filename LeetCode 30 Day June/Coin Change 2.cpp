//Top Down
class Solution {
public:
    
    int solve(vector<vector<int>>&dp,vector<int>&coins,int amount,int ind){
        if(amount==0)return 1;
        if(amount<0||ind==coins.size())return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        
        int sum1=solve(dp,coins,amount-coins[ind],ind);     //selected the coint but not incremented the ind as it can be selected again
        int sum2=solve(dp,coins,amount,ind+1);         //not selected the coin
        
        return dp[ind][amount]=sum1+sum2;
        
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount==0)return 1;
        if(coins.size()==0)return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(dp,coins,amount,0);
    }
};
//2D Dp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount==0)return 1;
        if(n==0)return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<=amount;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
};

//1D Dp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j]+=dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};