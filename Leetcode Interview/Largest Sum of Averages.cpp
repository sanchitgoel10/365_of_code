//Recursive Approach - Find recurrence equation
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int[] sum = new int[A.length];
        for (int i = 0;i < A.length; i++) sum[i] = A[i] + (i > 0 ? sum[i-1] : 0); 
        return h(A, K, sum, A.length, 0);
    }
    
    public double h(int[] A, int k, int[] sum, int len, int s) {
        if (k == 1) return ((double)(sum[len-1] - sum[s] + A[s]) / (len-s));
        double num = 0;
        for (int i = s; i + k <= len ; i++) {
            num = Math.max(num, ((double) (sum[i] - sum[s] + A[s]) / (i - s + 1)) + h(A, k-1, sum, len, i+1));
        }
        return num;
    }
}
//Recursion + Top-Bottom Memoralization - Seperate moving pieces
class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int[] sum = new int[A.length];
        for (int i = 0;i < A.length; i++) sum[i] = A[i] + (i > 0 ? sum[i-1] : 0); 
        double[][] dp = new double[A.length][K+1];
        return h(A, K, sum, dp, A.length, 0);
    }
    
    public double h(int[] A, int k, int[] sum, double[][] dp, int len, int s) {
        if (dp[s][k] != 0) return dp[s][k];
        if (k == 1){
            dp[s][k] = ((double)(sum[len-1] - sum[s] + A[s]) / (len-s));
            return dp[s][k];
        }
        for (int i = s; i + k <= len ; i++) {
            dp[s][k] = Math.max(dp[s][k], ((double) (sum[i] - sum[s] + A[s]) / (i - s + 1)) + h(A, k-1, sum, dp, len, i+1));
        }
        return dp[s][k];
    }
}

//C++
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int k) {
        int n=A.size();
        vector<int> sum(n+1,0);
        sum[0]=A[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+A[i];
        }
        vector<vector<double>> dp(n,vector<double>(k+1,0));
        
        return solve(sum,k,n,0,dp,A); 
    }
    double solve(vector<int>&sum,int k,int len,int start,vector<vector<double>>&dp,vector<int> &a){
        if(dp[start][k])return dp[start][k];
        if(k==1){
            dp[start][k]=(double)(sum[len-1]-sum[start]+a[start])/(len-start);
            return dp[start][k];
        }
        for(int i=start;i+k<=len;i++){        //basically chossing each possible interval in all possible k available.
            dp[start][k]=max(((double)(sum[i]-sum[start]+a[start])/(i-start+1)+solve(sum,k-1,len,i+1,dp,a)),dp[start][k]);
        }
        return dp[start][k];
    }
};