class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr=arr[0],wins=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>curr){
                curr=arr[i];
                wins=0;
            }
            if(++wins==k)break;
        }
        return curr;
    }
};