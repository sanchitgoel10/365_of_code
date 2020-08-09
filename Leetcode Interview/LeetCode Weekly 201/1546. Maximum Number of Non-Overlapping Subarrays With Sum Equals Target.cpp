class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int curr=0;
        unordered_map<int,int> m;
        m[0]=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(m.find(curr-target)!=m.end()){
                ans=max(ans,m[curr-target]+1);
            }
            m[curr]=ans;
        }
        return ans;
    }
};