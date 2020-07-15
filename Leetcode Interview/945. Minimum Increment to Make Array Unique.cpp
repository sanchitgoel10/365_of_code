/*
The idea is to sort the input -O(nlogn)- , then we move forward from the beginning of the array till the end.
As soon as we found a condition that the current element is less than or equal to the previous elements then we need to update the current array element.
here is an example of the given input.
A = [3,2,1,2,1,7]
Sorted A = [1,1,2,2,3,7]
After reaching the second 1 on the array since the condition is satisfied A[i]<=A[i-1] so we need to update the A[i] by A[i-1]+1.
At the same time we need to keep track of result by
result += A[i-1]+ 1 - A[i];

The rest of iterations are as following :

A = [1,2,2,2,3,7]
res= 1

A = [1,2,3,2,3,7]
res= 2

A = [1,2,3,4,3,7]
res= 4

A = [1,2,3,4,5,7]
res= 6
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int s = A.size();
        int res=0;
        sort(A.begin(),A.end());        
        for (int i=1; i<s; ++i) {
            if (A[i]<=A[i-1]){
                res+=A[i-1]+1 -A[i];
                A[i]= A[i-1]+1;
            }
        }
        return res;
    }
};