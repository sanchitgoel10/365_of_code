/*The goal here is that we want to maximize the amount of money we can get assuming we move first.

Here your dp[i][j] means the max value we can get if it it's our turn and only coins between i and j remain.(Inclusively)

So dp[i][i] means there is only one coin left, we just pick it, dp[i][i+1] means there are only two left, we then pick the max one.

Now we want to derive the more general case. dp[i][j] = max( something + v[i], something + v[j]), since we either will pick the i or j coin. The problem now turns to what "something" here will be.

A quick idea may bedp[i][j] = max( dp[i + 1][j] + v[i], dp[i][j - 1] + v[j]), but here dp[i + 1][j] and dp[i][j - 1] are not the values directly available for us, it depends on the move that our opponent make.

Then we assume our opponent is as good as we are and always make optimize move. The worse case is that we will get the minimal value out of all possible situation after our opponent make its move.

so the correct dp formula would be dp[i][j] = max( min (dp[i + 1][j - 1], dp[i + 2][ j]) + v[i], min (dp[i][j - 2], dp[i + 1][ j - 1]) + v[j]}) .
If we pick i, then the opponent need to deal with subproblem dp[i + 1][j], it either pick from i + 1 or j, which left us two choices: dp[i+2][j] and dp[i+1][j-1]. Since the opponent is smart and will choose the one that give us the smaller result, therefore min(dp[i+2][j], dp[i+1][j-1]). Similarly for the case if we pick j.
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()% 2 == 0) return true;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int myBest = utill(nums, dp, 0, n-1);
        return 2*myBest >= accumulate(nums.begin(), nums.end(), 0);
    }
    
    int utill(vector<int>& v, vector<vector<int>> &dp, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i] + min(utill(v,dp, i+1, j-1), utill(v, dp, i+2, j));
        int b = v[j] + min(utill(v,dp,i, j-2), utill(v,dp, i+1, j-1));
        dp[i][j] = max(a, b);
                        
        return dp[i][j];
    }
};