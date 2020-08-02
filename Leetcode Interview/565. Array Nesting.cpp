class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> vis(nums.size());
        int ans=0;
        int i=0;
        while(i<nums.size()){
            int x=nums[i];
            int temp=0;
            while(!vis[x]){
                vis[x]=1;
                temp++;
                x=nums[x];
            }
            ans=max(ans,temp);
            i++;
        }
        return ans;
    }
};