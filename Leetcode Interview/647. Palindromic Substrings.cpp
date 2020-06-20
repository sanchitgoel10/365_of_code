class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])ans++,l--,r++;
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])ans++,l--,r++;
        }
        return ans;
    }
};