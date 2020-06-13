class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a||b||c){
            int ba=a&1;
            int bb=b&1;
            int bc=c&1;
            if((ba|bb)!=bc){
                if(ba&&bb)ans+=2;
                else ans++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};