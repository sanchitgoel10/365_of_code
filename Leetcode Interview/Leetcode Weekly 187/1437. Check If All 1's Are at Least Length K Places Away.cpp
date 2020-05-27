class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int l=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]){
                if(l==-1)l=i;
                else{
                    if(i-l-1<k)return 0;
                    else l=i;
                }
            }
        }
        return 1;
    }
};