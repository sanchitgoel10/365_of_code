#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        while(i<n&&j<n){
            if(nums[i]==0&&nums[j]==0){
                j++;
            }else if(nums[i]==0&&nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;j++;
            }else{
                i++;
                j++;
            }
        }
    }
};