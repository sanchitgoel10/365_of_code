class Solution {
public:
    
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mi=(n-1)/2;
        int m=arr[mi];
        int i=0,j=n-1;
        vector<int> ans;
        int count=0;
        while(count<k){
            if(abs(arr[j]-m)>=abs(arr[i]-m)){
                ans.push_back(arr[j]);
                j--;
            }else{
                ans.push_back(arr[i]);
                i++;
            }
            count++;
        }
        return ans;
    }
};