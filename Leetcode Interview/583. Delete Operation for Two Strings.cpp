class Solution {
public:
    
    int solve(vector<vector<int>>&dp,int n,int m,string s1,string s2){
        if(m==0)return n;
        if(n==0)return m;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s1[0]==s2[0]){
            return dp[n][m]=solve(dp,n-1,m-1,s1.substr(1),s2.substr(1));
        }else{
            return dp[n][m]=1+min(solve(dp,n-1,m,s1.substr(1),s2),solve(dp,n,m-1,s1,s2.substr(1)));
        }
    }
    
    int minDistance(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(dp,n,m,s1,s2);
    }
};