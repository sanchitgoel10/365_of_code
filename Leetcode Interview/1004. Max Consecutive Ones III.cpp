//Easy to understand
class Solution {
public:
    /*
        Approach:
        1. The question translates to finding the max length of subArray with at most K 0s.
        2. Use sliding window technique.
        3. Keep count of the number of 0s found in the current window.
        4. If the count is > K, then increment l until the count goes to <=K.
        5. At each iteration find the maxLen.
        6. Time complexity: O( N ).
    
    */
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int maxLen = 0;
        for( int r = 0 ; r < A.size() ; ++r ) {
            if( A[ r ] == 0 ) K--;
            while( K<0 ) {
                if( A[ l ] == 0 ) ++K;
                ++l;
            }
            maxLen = max( maxLen, r - l + 1 );
        }
        return maxLen;
    }
};