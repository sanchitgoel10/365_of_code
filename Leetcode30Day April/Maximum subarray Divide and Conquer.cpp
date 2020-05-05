#include<bits/stdc++.h>
using namespace std;

int Divandconquer(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    int m=n/2;
    int LMSS=Divandconquer(arr,m);
    int RMSS=Divandconquer(arr+m,n-m);
    int ans=max(LMSS,RMSS);
    int lsum=INT_MIN,rsum=INT_MIN,sum=0;
    for(int i=m;i<n;i++){
        sum+=arr[i];
        rsum=max(rsum,sum);
    }
    sum=0;
    for(int i=m-1;i>=0;i--){
        sum+=arr[i];
        lsum=max(lsum,sum);
    }
    ans=max(ans,lsum+rsum);
    return ans;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arr[nums.size()];
        copy(nums.begin(),nums.end(),arr);
        int ans=Divandconquer(arr,nums.size());
        return ans;
    }
};