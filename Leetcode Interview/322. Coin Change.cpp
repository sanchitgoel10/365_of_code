class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        sort(coins.begin(),coins.end());
        dp[0]=0;                   //number of coins hai ye number of ways nhi ki 1 ayega yaha
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i)break;
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
            //cout<<dp[i]<<endl;
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};