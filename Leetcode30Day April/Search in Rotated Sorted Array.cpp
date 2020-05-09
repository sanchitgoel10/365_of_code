#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        
        int l=0;
        int h=nums.size()-1;
        while(l<h){                    //Finding the smallest element 
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[h]){
                l=mid+1;
            }else{
                h=mid;
            }
        }
        int start=0;
        int end=nums.size()-1;
        if(target>=nums[l]&&target<=nums[end]){         //checking in which size of array is our target present
            start=l;
        }else{
            end=l;
        }
        while(start<=end){              //normal binary search
            int mid=start+(end-start)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target)end=mid-1;
            if(nums[mid]<target)start=mid+1;
        }
        return -1;
    }
};