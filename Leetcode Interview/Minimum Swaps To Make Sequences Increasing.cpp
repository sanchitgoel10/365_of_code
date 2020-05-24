/*this problem can be solved using dynamic programming, at each position, we can choose to swap or not. Since we want two sorted arrays, at each position, whether to swap or not depends on the choice at previous position, so we can form a recursive formula.

When A[0, i-1] and B[0, i - 1] are sorted, since "It is guaranteed that the given input always makes it possible.". There are two cases on index i:

They are both still sorted when add number at index i, A[i] > A[i - 1] && B[i] > B[i - 1]
They are not sorted when add number at index i, in this case, only A[i] > B[i - 1] && B[i] > A[i - 1] can guarantee that "the given input always makes it possible".
Here we use :

swap[i] to represent the minimum swaps to make the A[0, i] and B[0, i] sequences increasing for 0 <= i <= n in condition that we swap A[i] and B[i].
no_swap[i] to represent the minimum swaps to make the A[0, i] and B[0, i] sequences increasing for 0 <= i <= n in condition that we don't swap A[i] and B[i].
*/
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const size_t n = A.size();
        vector<int> swap(n, n), no_swap(n, n);
        swap[0] = 1;
        no_swap[0] = 0;
        for (size_t i = 1; i < n; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                // If we swap position i, we need to swap position i - 1.
                swap[i] = swap[i - 1] + 1;
                
                // If we don't swap position i , we should not swap position i - 1.
                no_swap[i] = no_swap[i - 1];
            }
            
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                // If we swap position i, we should not swap position i - 1.
                swap[i] = std::min(swap[i], no_swap[i - 1] + 1);
                
                // If we don't swap position i, we should swap position i - 1.
                no_swap[i] = std::min(no_swap[i], swap[i - 1]);
            }
        }
        
        return std::min(swap.back(), no_swap.back());
    }
};