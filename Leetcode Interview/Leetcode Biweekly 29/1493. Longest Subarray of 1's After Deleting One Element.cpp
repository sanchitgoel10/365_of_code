//Also can be done with sliding window 1004 type

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n),b(n);       //forward and backward array
        f[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]){
                f[i]=f[i-1]+1;
            }else{
                f[i]=0;
            }
        }
        b[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]){
                b[i]=b[i+1]+1;
            }else{
                b[i]=0;
            }
        }
        int ans=nums[0]||nums[n-1];    //agar first ya last element 1 hai to ans 1 to hoga hi
        for(int i=1;i<n-1;i++){
            ans=max(ans,f[i-1]+b[i+1]);
        }
        return ans;
    }
};