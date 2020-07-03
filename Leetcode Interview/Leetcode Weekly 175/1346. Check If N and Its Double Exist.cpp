class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(), arr.end());
        bool seen0=false;
        for(int i=0;i<arr.size();i++) {
            if(arr[i]==0) {
                if(seen0) return true;       //multiple zeros
                seen0=true;
            }
            else if(nums.find(2*arr[i])!=nums.end()) return true;
        }
        return false;
    }
};