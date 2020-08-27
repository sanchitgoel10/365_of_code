class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n:nums){
            if(m[n])return true;
            m[n]++;
        }
        return false;
    }
};