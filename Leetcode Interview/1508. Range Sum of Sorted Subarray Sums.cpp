class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int m = 1000000007;
        for(int i =0; i < nums.size(); ++i)
        {
            int s = nums[i];
            pq.push(s);
            for(int j = i +1; j < nums.size(); ++j)
            {
                s = (s%m + nums[j])%m;
                pq.push(s);
            }
        }
        int res = 0;
        for(int i = 0; i < right; ++i)
        {
            if(i >= left-1)
                res = (res%m + pq.top())%m;
            pq.pop();
        }
        return res;
    }
};