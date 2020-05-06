#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=-1;
        int elc=0;
        for(auto i:nums){
            if(i==el){
                elc++;
            }else if(elc==0){
                el=i;
                elc=1;
            }else{
                elc--;
            }
        }
        return el;
    }
};