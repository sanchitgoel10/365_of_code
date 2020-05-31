class Solution {
public:
    int edithelper(string s1,string s2,int m,int n,vector<vector<int>> &dp)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(dp[m][n]>-1)
            return dp[m][n];
        if(s1[0]==s2[0])
        {
            dp[m][n]=edithelper(s1.substr(1),s2.substr(1),m-1,n-1,dp);
            return dp[m][n];
        }else{
            int option1=1+edithelper(s1.substr(1),s2.substr(1),m-1,n-1,dp);
            int option2=1+edithelper(s1,s2.substr(1),m,n-1,dp);
            int option3=1+edithelper(s1.substr(1),s2,m-1,n,dp);
            dp[m][n]=min(option1,min(option2,option3));
            return dp[m][n];
        }

    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return edithelper(word1,word2,m,n,dp);   
    }
};