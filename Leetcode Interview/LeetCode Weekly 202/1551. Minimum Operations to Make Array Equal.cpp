class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        int i=1;
        while(i<=n){
            ans+=n-i;
            i+=2;
        }
        return ans;
    }
};