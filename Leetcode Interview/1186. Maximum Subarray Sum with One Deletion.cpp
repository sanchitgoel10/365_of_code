/*
Eg arr= [-2,-3,4,-1,-2,1,5,-3]
forward=[-2,-3,4,3,1,2,7,4]
backward=[2,4,7,3,4,6,5,-3] 
*/
int maximumSum(vector<int>& arr) {
        /**
         * sumEndsHere[i] : The max sum of the subarray ends at arr[i]
         * sumStartHere[i]: The max sum of the subarray starts at arr[i]
         * There two situation which can obtain the maximum subarray sum
         *  1. Get max sum without deleting any element.
         *  2. Get max sum by deleting one element. If we delete arr[i], then the 
         *     max sum of subarray is 
         *          sumEndsHere[i-1] + sumStartHere[i+1]
         *            (left to i)        (right to i)
         */
        // Time complexity : O(n)
        // Space complexity: O(n)
        vector<int> sumEndsHere(arr.size()), sumStartHere(arr.size());
        int ans = INT_MIN, size = arr.size();
        for(int i = 0, curSumF = 0, curSumB = 0; i<size; i++) {
            curSumF += arr[i];
            curSumB += arr[size-1-i];
            ans = max(ans, max(curSumF, curSumB));        //when we dont delete anything also corner case that is deleting first and last elements
            sumEndsHere[i] = curSumF;
            sumStartHere[size-1-i] = curSumB;
            curSumF = max(curSumF, 0);
            curSumB = max(curSumB, 0);
        }
        for(int i = 1; i<size-1; i++){
            ans = max(ans, sumEndsHere[i-1]+sumStartHere[i+1]);
        }
        return ans;
    }

//Another smart solution
int maximumSum(vector<int>& arr) {
        int size = arr.size();
        if ( size == 1 ) return arr[ 0 ];

        // dropped record the maximum sum ended at current index with one number being dropped
        int dropped = max( arr[ 0 ], arr[ 1 ] );
        // not dropped must take arr[ 1 ] at index = 1
        int notDropped = max( arr[ 0 ] + arr[ 1 ], arr[ 1 ] );
        int ans = max( dropped, notDropped );
            
        for ( int i = 2; i < size; i++ ) {
            dropped = max( notDropped, arr[ i ] + dropped );
            notDropped = max( notDropped + arr[ i ], arr[ i ] );
            ans = max( ans, max( dropped, notDropped ) );
        }
        return ans;
    }