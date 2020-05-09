#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int ans=0;
        m[0]=1;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            if(m.count(sum-k))ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};