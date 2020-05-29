//Since, it is 132 pattern. The smallest of the three is in front of the other two. We'd better scan from back to front.
 //In this way, we can maintain //a pair of biggest numbers (S3 and S2) and looking for S1 which is smaller than S2 (S1 < S2). 
 //Otherwise, we pop numbers in stack and update S2 
 //accordingly.

/*
eg [3,1,7,6,8,5]
eg [3,1,7,6,8,2]
eg [3,1,7,4,8,5]
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int s2 = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < s2)
                return true;
            
            while (!stk.empty() && stk.top() < nums[i]) {       //s2 just chota s3 se.
                s2 = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
