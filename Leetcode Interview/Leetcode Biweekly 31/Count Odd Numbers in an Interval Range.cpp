class Solution {
public:
    int countOdds(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++)if(i%2)ans++;
        return ans;
    }
};