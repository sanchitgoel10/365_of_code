vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}
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