class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i=0,j=n;
        int x=0;
        while(i<n||j<2*n){
            if(x%2==0){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
            x++;
        }
        return ans;
    }
};