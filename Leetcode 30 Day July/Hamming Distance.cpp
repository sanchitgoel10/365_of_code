class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=0;i<32;i++){
            int bx=x&1;
            int by=y&1;
            ans+=(bx^by);
            x=x>>1;
            y=y>>1;
        }
        return ans;
    }
};