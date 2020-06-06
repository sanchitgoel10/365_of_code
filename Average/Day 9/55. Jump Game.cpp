#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastgoodposition=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=lastgoodposition){
                lastgoodposition=i;
            }
        }
        return lastgoodposition==0;
    }
};