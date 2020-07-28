//dp[diff][index] equals to the length of arithmetic sequence at index with difference diff.

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans=2;
        unordered_map<int,unordered_map<int,int>> dp;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=A[j]-A[i];
                dp[d][j]=dp[d].count(i)?dp[d][i]+1:2;
                ans=max(ans,dp[d][j]);
            }
        }
        return ans;
    }
};