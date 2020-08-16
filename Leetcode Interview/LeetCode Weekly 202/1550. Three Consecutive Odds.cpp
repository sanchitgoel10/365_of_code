class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int l=0;
        for(auto n:arr){
            if(n%2)l++;
            else l=0;
            if(l==3)return 1;
        }
        return 0;
    }
};