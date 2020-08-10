class Solution {
public:
    int titleToNumber(string s) {
        long ans=0;
        long d=1;
        for(int i=s.size()-1;i>=0;i--){
            ans+=(d*(s[i]-'A'+1));
            d*=26;
        }
        return int(ans);
    }
};