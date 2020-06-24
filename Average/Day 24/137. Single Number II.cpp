class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bitSum=0;
            for(int num:nums){
                bitSum+=((num>>i)&1);
            }
            if(bitSum%3){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};