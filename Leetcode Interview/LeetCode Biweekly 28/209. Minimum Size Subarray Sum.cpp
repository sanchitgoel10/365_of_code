class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // from the left, min length of array with sum = target
        vector<int> left = minLen(arr, target);  //prefix array

        // from the right, min length of array with sum = target
        reverse(arr.begin(), arr.end()); //reverse array and send
        vector<int> right = minLen(arr, target);
        
        reverse(right.begin(),right.end()); //reverse righ to make it suffix array
        
        // consider each position to find the min sum of length of the two array with target sum
        int min_val = arr.size() + 1;
        int n = arr.size();
        for(int i = 0; i < arr.size() - 1; ++i) {
            min_val = min(min_val, left[i] + right[i+1]);
        }
        return min_val == arr.size() + 1 ? -1 : min_val;
    }
    
    // at each position, i, find the min length of array with target sum 
    vector<int> minLen(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<int, int> idx;
        vector<int> ans(n, n + 1);
        idx[0] = -1;
        int sum=0;
        for(int i = 0; i < arr.size(); ++i) {
            sum+=arr[i];
            int len=n+1;
            if(idx.find(sum-target)!=idx.end()){
                len=i-idx[sum-target];
            }
            idx[sum]=i;
            ans[i]=i==0?len:ans[i]=min(ans[i-1],len);
        }
        return ans;
    }
    
};