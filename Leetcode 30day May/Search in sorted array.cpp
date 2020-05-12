#include<bits/stdc++.h>
using namespace std;

/*
All elements before the required have first occurrence at even index (0, 2, ..) 
and next occurrence at odd index (1, 3, …). And all elements after the required 
element have first occurrence at odd index and next occurrence at even index.

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    l=mid+2;
                }else{
                    h=mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    l=mid+1;
                }else{
                    h=mid;
                }
            }
        }
        return nums[l];
    }
};