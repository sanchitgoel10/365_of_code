/*
For each integer A[i],
we may choose either x = -K or x = K.

If we add K to all B[i], the result won't change.

It's the same as:
For each integer A[i], we may choose either x = 0 or x = 2 * K.

Explanation:
We sort the A first, and we choose to add x = 0 to all A[i].
Now we have res = A[n - 1] - A[0].
Starting from the smallest of A, we add 2 * K to A[i],
hoping this process will reduce the difference.

Update the new mx = max(mx, A[i] + 2 * K)
Update the new mn = min(A[i + 1], A[0] + 2 * K)
Update the res = min(res, mx - mn)

I don't understand why mn = min（A [i + 1]，A [0] + 2 * K）; does the mn is not A[0]?

Because the idea is to add 2K to each one and find the result, A[0] has already be changed to A [0] + 2 * K.
You may still ask, hey I can keep A[0] when dealing with A[2] + 2K , but that's unnecessary, the gold is to find to smallest difference. If you keep A[0], it is the smallest, but for what? It cant be the result because we want to reduce the difference, so we would like to make smallest number bigger as possible.
*/
class Solution {
public:
    int smallestRangeII(vector<int> A, int K) {
        sort(A.begin(), A.end());
        int n = A.size(), mx = A[n - 1], mn = A[0], res = mx - mn;
        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, A[i] + 2 * K);
            mn = min(A[i + 1], A[0] + 2 * K);
            res = min(res, mx - mn);
        }
        return res;
    }
};