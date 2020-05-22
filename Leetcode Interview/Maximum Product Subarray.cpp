class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curmax = nums[0], curmin = nums[0], res = nums[0];
        for(int i=1; i<nums.size(); ++i){
            int premax = curmax;
            curmax = max(curmax*nums[i], max(curmin*nums[i], nums[i]));
            curmin = min(premax*nums[i], min(curmin*nums[i], nums[i]));
            res = max(res, curmax);
        }
        return int(res);
    }
};