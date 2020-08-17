class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=-1,ele2=-1,elc1=0,elc2=0;
        for(auto n:nums){
            if(n==ele1)elc1++;
            else if(n==ele2)elc2++;
            else if(elc1==0){
                ele1=n;
                elc1++;
            }else if(elc2==0){
                ele2=n;
                elc2++;
            }else{
                elc1--;
                elc2--;
            }
        }
        int cnt1=0,cnt2=0;
        for(auto n:nums){
            if(n==ele1)cnt1++;
            if(n==ele2)cnt2++;
        }
        vector<int> ans;
        if(cnt1>nums.size()/3)ans.push_back(ele1);
        if(cnt2>nums.size()/3)ans.push_back(ele2);
        return ans;
    }
};