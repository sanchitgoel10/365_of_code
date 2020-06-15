class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left=*max_element(weights.begin(),weights.end());  //itna to min hoga hi container warna max element ko nhi leke jaa payega
        int right=100000000;
        while(left<right){
            int mid=(left+right)/2;
            int total=1;
            int acc=0;
            for(auto w:weights){
                if(acc+w<=mid){
                    acc+=w;
                }else{
                    acc=w;
                    total++;
                }
            }
            if(total<=D){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};