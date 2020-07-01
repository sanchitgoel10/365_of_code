class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        int i=1;
        while((n-i)>=0){
            n-=i;
            ans++;
            i++;
        }
        return ans;
    }
};