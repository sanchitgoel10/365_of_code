class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=INT_MAX;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            ans=min(ans,sum);
        }
        return ans>0?1:abs(ans)+1;
    }
};