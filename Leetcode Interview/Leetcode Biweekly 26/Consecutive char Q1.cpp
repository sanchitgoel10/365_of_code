class Solution {
public:
    int maxPower(string s) {
        char l=s[0];
        int ans=1;
        int c=1;
        for(int i=1;i<s.size();i++){
            if(l==s[i]){
                c++;
                ans=max(ans,c);
            }else{
                c=1;
                l=s[i];
            }
        }
        return ans;
    }
};