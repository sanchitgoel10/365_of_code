/*The O(n) solution is to use two pointers: l and r. First we move r until we get a sum >= s, 
then we move l to the right until sum < s. In this process, store the minimum length between l and r. 
Since each element in nums will be visited by l and r for at most once. This algorithm is of O(n) time.
*/


//Works only on positive array
/*
The reason why we stop incrementing start when we violate the condition is that we 
are sure we will not satisfy it again if we keep incrementing start. In other words, 
if the sum of the current subarray start -> end is smaller than the target then the 
sum of start+1 -> end is neccessarily smaller than the target. (positive values)
The problem with this solution is that it doesn't work if we have negative values, 
this is because of the sentence above Once we "violate" the condition we stop incrementing start.
*/

//brother question  862 

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (sum >= s) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};