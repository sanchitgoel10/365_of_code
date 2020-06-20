class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int maxkey=0;
        
        unordered_map<int,vector<int>> m;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
                maxkey=max(maxkey,i+j);
            }
        }
        for(int i=0;i<=maxkey;i++){
            for(auto j=m[i].rbegin();j!=m[i].rend();j++){
                ans.push_back(*j);
            }
        }
        return ans;
    }
};