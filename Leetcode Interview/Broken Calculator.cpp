/*Instead of multiplying by 2 or subtracting 1 from X, we could divide by 2 (when Y is even) or add 1 to Y.

The motivation for this is that it turns out we always greedily divide by 2:

If say Y is even, then if we perform 2 additions and one division, we could instead perform one division and one addition for less operations [(Y+2) / 2 vs Y/2 + 1].

If say Y is odd, then if we perform 3 additions and one division, we could instead perform 1 addition, 1 division, and 1 addition for less operations [(Y+3) / 2 vs (Y+1) / 2 + 1].

*/

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int x=X;
        int y=Y;
        if(x>y)return x-y;
        int ans=0;
        while(y>x){
            ans++;
            if(y%2==1)y++;
            else y/=2;
        }
        return ans+x-y;
    }
};