#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> m;
        int ans=0;
        int sum=0;
        m[0]=-1;          //for the case when sum is zero then upto that point we have to consider whole length
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                sum++;
            }else{
                sum--;
            }
            if(m.count(sum)==0){
                m[sum]=i;
            }else{
                ans=max(ans,i-m[sum]);
            }
            
        }
        return ans;
    }
};