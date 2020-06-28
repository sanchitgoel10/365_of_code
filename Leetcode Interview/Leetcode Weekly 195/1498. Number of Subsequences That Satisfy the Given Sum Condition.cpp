/*Almost same as problem two sum.
If we want to know the count of subarray in sorted array A,
then it's exactly the same.
Make sure you can do two sum before continue.


Explanation
Sort input A first,
For each A[i], find out the maximum A[j]
that A[i] + A[j] <= target.

For each elements in the subarray A[i+1] ~ A[j],
we can pick or not pick,
so there are 2 ^ (j - i) subsequences in total.
So we can update res = (res + 2 ^ (j - i)) % mod.

We don't care the original elements order,
we only want to know the count of sub sequence.
So we can sort the original A, and the result won't change.


Complexity
Time O(NlogN)
Space O(1) for python
(O(N) space for java and c++ can be save anyway)
Does sorting not affect the solution?
yeah, but we only need to consider the maximum and minimum elements in the subsequence,so the overall order doesn't matter.
*/

int numSubseq(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r) {
            if (A[l] + A[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }