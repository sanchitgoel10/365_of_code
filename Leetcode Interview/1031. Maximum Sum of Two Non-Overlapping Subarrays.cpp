/*
Lsum, sum of the last L elements
Msum, sum of the last M elements

Lmax, max sum of contiguous L elements before the last M elements.
Mmax, max sum of contiguous M elements before the last L elements/
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); ++i)
            A[i] += A[i - 1];
        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            Lmax = max(Lmax, A[i - M] - A[i - M - L]);
            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
            int Lsum = A[i] - A[i-L];
            int Msum = A[i] - A[i-M];
            res = max(res, max(Lmax + Msum, Mmax + Lsum));
        }
        return res;
    }
};