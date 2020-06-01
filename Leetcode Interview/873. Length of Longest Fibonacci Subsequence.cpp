/*
Save array A to a hash set s.
Start from base (A[i], A[j]) as the first two element in the sequence,
we try to find the Fibonacci like subsequence as long as possible,

Initial (a, b) = (A[i], A[j])
While the set s contains a + b, we update (a, b) = (b, a + b).
In the end we update the longest length we find.
O(n2logm)  m=max(A);
*/
int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int  a = A[i], b = A[j], l = 2;
                while (s.count(a + b))
                    b = a + b, a = b - a, l++;
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
/*
Another solution is kind of dp.
dp[a, b] represents the length of fibo sequence ends up with (a, b)
Then we have dp[a, b] = (dp[b - a, a] + 1 ) or 2
The complexity reduce to O(N^2).
*/
int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> m;
        int N = A.size(), res = 0;
        int dp[N][N];
        for (int j = 0; j < N; ++j) {
            m[A[j]] = j;
            for (int i = 0; i < j; ++i) {
                int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
                dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
                res = max(res, dp[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }