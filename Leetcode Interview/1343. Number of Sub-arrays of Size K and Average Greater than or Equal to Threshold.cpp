class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int ans=0;
        int curr_sum=0;
        for(int i=0;i<k;i++){
            curr_sum+=arr[i];
        }
        if(double(curr_sum)/double(k)>=double(t))ans++;
        for(int i=k;i<arr.size();i++){
            curr_sum-=arr[i-k];
            curr_sum+=arr[i];
            if(double(curr_sum)/double(k)>=double(t))ans++;
        }
        return ans;
    }
};