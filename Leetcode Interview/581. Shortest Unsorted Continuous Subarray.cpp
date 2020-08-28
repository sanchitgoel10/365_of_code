//Sort

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == sorted[i]) {
            i++;
        }
        while (j > i && nums[j] == sorted[j]) {
            j--;
        }
        return j + 1 - i;
    }
};
/*
max on left, min on right - O(N)
The idea is that:

From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;
Those 2 can be easily checked if we build 2 vectors:

max so far from the left,
and min so far from the right;
/**
 *            /------------\
 * nums:  [2, 6, 4, 8, 10, 9, 15]
 * minr:   2  4  4  8   9  9  15
 *         <--------------------
 * maxl:   2  6  6  8  10 10  15
 *         -------------------->
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxlhs(n);   // max number from left to cur
        vector<int> minrhs(n);   // min number from right to cur
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minrhs[i]) i++;
        while (j > i && nums[j] >= maxlhs[j]) j--;      //j>i dekh

        return j + 1 - i;
    }
};