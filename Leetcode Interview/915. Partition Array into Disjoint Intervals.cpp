/*
suppose the original left subarray is from 0 to partitionIdx, the max value of that is localMax. If it is a valid partition, every value from partitionIdx + 1 to end should be >= localMax. But if we find a value in the right part, a[i], is smaller than localMax, which means the partition is not correct and we have to incorporate a[i] to form the left subarray. So the partitionIdx is set to be i, and we have to recalculate the max value of the new left subarray.(recorded in max)


*/

public int partitionDisjoint(int[] a) {
        int localMax = a[0], partitionIdx = 0, max = localMax;
        for (int i = 1; i < a.length; i++)
            if (localMax > a[i]) {
                localMax = max;
                partitionIdx = i;
            } else max = Math.max(max, a[i]);
        return partitionIdx + 1;
    }

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> mx(A.size()), mi(A.size());
        mx[0]=A[0]; mi[A.size()-1]=A.back();
        for(int i=1; i<A.size(); i++)
            mx[i]=max(A[i], mx[i-1]);
        for(int i=A.size()-2; i>=0; i--)
            mi[i]=min(A[i], mi[i+1]);
        int i;
        for(i=0; i<A.size()-1; i++)
            if(mx[i]<=mi[i+1])
                break;
        return i+1;
    }
};