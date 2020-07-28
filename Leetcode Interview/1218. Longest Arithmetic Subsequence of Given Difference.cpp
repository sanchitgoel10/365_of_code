class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=1;
        unordered_map<int,int> dp;
        for(auto &i:arr){
            if(dp.count(i-difference)){
                dp[i]=dp[i-difference]+1;
            }else{
                dp[i]=1;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    
};