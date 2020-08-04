/*
There are 3 buckets which numbers in can be placed into:

less than L
less than or equal to R
greater than R
Bucket 1 is a subset of Bucket 2. Return the ongoing count of bucket 2 numbers minus the ongoing count of bucket 1 numbers. Completely ignore bucket 3. The ongoing count of bucket 1 and 2 is reset back to 0 when a number no longer meets the ongoing count criteria ( "less than L" for bucket 1 and "less than or equal to R" for bucket 2 ).

Verbose Solution #1:
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,lessThanLeft=0,lessThanOrEqToRight=0;
        for (auto n: A){
 
            if (n<L)
                ++lessThanLeft;
            else
                lessThanLeft=0;
            
            if (n<=R)
                ++lessThanOrEqToRight;
            else
                lessThanOrEqToRight=0;
            
            cnt+=lessThanOrEqToRight-lessThanLeft;
        }
        return cnt;
    }
};