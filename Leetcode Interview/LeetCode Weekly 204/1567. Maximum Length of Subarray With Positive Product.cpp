/*
We shouldn't include 0 in the subarray. So we just handle each of the subarrays surrounded by 0s.
If there are even number of negative numbers in the subarray, the entire subarray has a positive product.
If there are odd number of negative numbers in the subarray, we have two candidates:
From the first element of the subarray to the element before the last negative element
From the next element of first negative element to the last element of the subarray.
*/
class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int j = 0, N = A.size(), ans = 0;
        while (j < N) {
            int i = j, cnt = 0, first = -1, last = -1;
            while (j < N && A[j] != 0) {
                cnt += A[j] < 0;
                if (A[j] < 0) {
                    if (first == -1) first = j;
                    last = j;
                }
                ++j;
            }
            if (cnt % 2) ans = max({ ans, j - first - 1, last - i });
            else ans = max(ans, j - i);
            while (j < N && A[j] == 0) ++j;
        }
        return ans;
    }
};