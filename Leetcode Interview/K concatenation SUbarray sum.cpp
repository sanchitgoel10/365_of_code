/*Calculate the total sum of elements of the array:
int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9+7;

This part is Kadane's algorithm used to find maximum sum subarray.
When K=1, It will find the maximum sum subarray.
When K>1, It will find the maximum sum subarray when suffix of first array and prefix of next array are combined together.

The maximum sum will be maximum of the following:
a) 0 (if all the elements are negative in the array)
b) k * sum of all elements of array
c) maximum suffix sum + maximum prefix sum (when k = 2)
d) maximum suffix sum + maximum prefix sum + (k-2) sum of all elements of array

return max<int64_t>({0, mx, total * max(0, k - 2) + mx}) % mod;
*/


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size(), sum = arr[0], mx = arr[0];
	    int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9+7;
	    for (int i = 1; i < n * min(k, 2); i++) {                           //mx is kadane if k==1 or suffix and prefix walaif k==2
	        sum = max(arr[i % n], sum + arr[i % n]);
	        mx = max(mx, sum);
	    }
	    return max<int64_t>({0, k*total, mx , total * max(0, k - 2) + mx}) % mod;
    }
};