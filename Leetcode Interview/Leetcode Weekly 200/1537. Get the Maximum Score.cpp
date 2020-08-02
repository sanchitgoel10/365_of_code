/*
Explanation: Because both arrays are the increasing array including positive integer, that why dp is a good choice in this problem.
We have:

dp1[i] is the maximum of value if we start from any array and reach to index i of array 1.
dp2[i] has the same meaning: the maximum of value if we start from any array and reach to index i of array 2.
To calculate these dp arrays more effectively, we start from the beginning index for each array and calculate with linear time.
Start from i = 0 with array 1 and j = 0 with array 2.

Formula:

dp1[i] = dp2[j] = max(dp1[i-1], dp2[j-1]) + nums1[i] with nums1[i] = nums2[j]
dp1[i] = dp1[i-1] + nums1[i] with nums1[i] < nums2[j]
dp2[j] = dp2[j-1] + nums2[j] with nums2[j] < nums1[i]
Because we always use the value from the previous index for each calculation in dp1 and dp2, therefore no need to store it in an array and can reduce the space complexity from O(N) to O(1).
*/
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        long dp1 = 0, dp2 = 0, res = 0;
        for (int i = 0, j = 0; i < m || j < n;) {
            if (i < m && j < n && nums1[i] == nums2[j])
                dp1 = dp2 = max(dp1, dp2) + min(nums1[i++], nums2[j++]);
            else if (i < m && ((j < n && nums1[i] < nums2[j]) || j == n))
                dp1 += nums1[i++];
            else
                dp2 += nums2[j++];
        }
        int mod = 1e9 + 7;
        return max(dp1, dp2) % mod;
    }
};