class Solution {
public:
    int*freq=new int[10002]();
    int*dp=new int[10002]();
    int deleteAndEarn(vector<int>& nums) {
        for(auto i:nums){
            freq[i]++;
        }
        dp[1]=freq[1];
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
        }
        return dp[10000];
    }
};