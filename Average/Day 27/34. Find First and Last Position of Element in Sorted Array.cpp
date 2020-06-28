class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        if(!nums.size())return ans;
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==nums.size())return ans;
        if(nums[l]!=target)return ans;
        int h=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        ans[0]=l;
        ans[1]=h;
        return ans;
        
    }
};