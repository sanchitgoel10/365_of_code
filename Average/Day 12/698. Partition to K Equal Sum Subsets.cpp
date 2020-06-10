class Solution {
public:
    int target;
    
    bool solve(int ind,vector<int>&nums,vector<int>&bucket){
        for(int i=0;i<bucket.size();i++){
            if(bucket[i]+nums[ind]>target)continue;
            bucket[i]+=nums[ind];
            if(ind==nums.size()-1)return true;   //last element bhi add ho gaya
            if(solve(ind+1,nums,bucket)){
                return true;
            }else{
                bucket[i]-=nums[ind];
                if(bucket[i]==0)return false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(auto i:nums)sum+=i;
        if(sum%k)return false;
        target=sum/k;
        vector<int> bucket(k,0);
        if(nums[0]>target)return false;
        return solve(0,nums,bucket);
    }
    
};