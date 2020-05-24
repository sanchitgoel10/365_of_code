/*
Idea
This is a typical Dynamic Programming problem. The only trick lies in the non-emptiness.

Target: We want to calculate the maximal dot product for nums1[0:i] and nums2[0:j]
Base case
When i == 0 or j == 0, we return -inf. (Because this is an empty case, which is intolerable)
State Transition, for any i > 0 and j > 0, there are 4 possibilities
nums1[i - 1] is not selected, dp[i][j] = dp[i - 1][j]
nums2[j - 1] is not selected, dp[i][j] = dp[i][j - 1]
Neither nums1[i - 1] or nums2[j - 1] is selected, dp[i][j] = dp[i - 1][j - 1]
Both nums1[i - 1] and nums2[j - 1] are selected, dp[i][j] = max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]
Since we already selected one pair (nums1[i - 1], nums2[j - 1]), we can assume the minimal proceeding value is 0
Complexity

Time: O(mn)
Space: O(m)
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = int(nums1.size()), m = int(nums2.size());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], 0) + nums1[i - 1] * nums2[j - 1]);
            }
        }
        return dp[n][m];
    }
};