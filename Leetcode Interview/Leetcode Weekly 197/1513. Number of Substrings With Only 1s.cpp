class Solution {
public:
    int numSub(string s) {
        vector<int> dp(s.size(),0);
        dp[0]=s[0]=='1'?1:0;
        int ans=dp[0];
        int mod=1e9+7;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                dp[i]=dp[i-1]+1;
            }else{
                dp[i]=0;
            }
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};