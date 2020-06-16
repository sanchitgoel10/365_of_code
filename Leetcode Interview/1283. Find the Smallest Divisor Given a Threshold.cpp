class Solution {
public:
    int smallestDivisor(vector<int>& nums, int thres) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid=(left+right)/2;
            int t=0;
            for(auto num:nums){
                t+=(num+mid-1)/mid;
            }
            if(t<=thres){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};