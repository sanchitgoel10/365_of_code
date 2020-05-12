#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int n = matrix.size();
        if(n == 0) return -1;
        int minval = matrix[0][0] , maxval = matrix[n - 1][n - 1], mid;
        while(minval < maxval)
        {
            mid = minval + ((maxval - minval) >> 1);//find the middle value of the range between maxval and minval
            int count = 0, j = n - 1;
            for(int i = 0; i < n && matrix[i][0] <= mid; i++)//count how many number of elements in the matrix less than middle value. 
            {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += j + 1;
            }
            if(count < k)
            minval = mid + 1;
            else
            maxval = mid;
        }
        return minval;
    }
};