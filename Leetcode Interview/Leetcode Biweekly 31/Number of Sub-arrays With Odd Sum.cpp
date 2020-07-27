/*
This is an elementary dynamic programming problem.
odd[i] records the number of subarray ending at arr[i] that has odd sum.
even[i] records the number of subarray ending at arr[i] that has even sum.
if arr[i + 1] is odd, odd[i + 1] = even[i] + 1 and even[i + 1] = odd[i]
if arr[i + 1] is even, odd[i + 1] = odd[i] and even[i + 1] = even[i] + 1
Since we only required the previous value in odd and even, we only need O(1) space.
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int odd=0,even=0;
        int ans=0;
        for(auto i:arr){
            int oldodd=odd;
            int oldeven=even;
            if(i%2){
                odd=oldeven+1;
                even=oldodd;
            }else{
                odd=oldodd;
                even=oldeven+1;
            }
            ans=(ans+odd)%mod;
        }
        return ans;
    }
};