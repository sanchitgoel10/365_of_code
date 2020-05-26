/*LSB is 1/0 for both numbers - for these kind of pairs they will not contribute in the final result
LSB is different - these pairs will contribute at final result
Divide all the numbers into two groups p & q.
p - contains numbers whose LSB is 1
q - numbers whose LSB is 0

The pairs obtained from elements of only p or only q will be the pairs of the first type given above.
So only the pairs obtained from combination of p and q will contribute at the result. And the contribution will be
|p| * |q| = |p| * (|n| - |p|); |p| = size of set p, |q| = size of set q, |n| = size of input array,

And we need to do the same process for all the 8 * sizeof(int) bits of all numbers and sum the each bits hamming contribution.

Runtime will be O(8 * sizeof(int) *n) = O(n)
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        
        int res = 0;
        
        for(int i=0;i<32;i++) {
            int setCount = 0;
            for(int j=0;j<nums.size();j++) {
                if ( nums[j] & (1 << i) ) setCount++;
            }
            
            res += setCount * (nums.size() - setCount);
        }
        
        return res;
    }
};