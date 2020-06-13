//Similar to LIS problem 
//O(n^2)


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)return nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> prev(n,-1),dp(n,1),ans;
        int maxsubsetind=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        prev[i]=j;            //keeps track of diff subset like parent array 
                        dp[i]=dp[j]+1;
                    }
                }
            }
            if(dp[maxsubsetind]<dp[i]){
                maxsubsetind=i;
            }
        }
        while(maxsubsetind!=-1){
            ans.push_back(nums[maxsubsetind]);
            maxsubsetind=prev[maxsubsetind];
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};