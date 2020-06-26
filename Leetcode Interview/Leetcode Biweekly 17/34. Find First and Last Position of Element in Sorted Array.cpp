class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i+=2){
            int f=nums[i];
            int val=nums[i+1];
            vector<int> v(f,val);
            ans.insert(ans.end(),v.begin(),v.end());
        }
        return ans;
    }
};