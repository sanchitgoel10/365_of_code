class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int ans=0;
        string ret="";
        int st=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                int curr=r-l+1;
                if(curr>ans){
                    ans=curr;
                    st=l;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                int curr=r-l+1;
                if(curr>ans){
                    ans=curr;
                    st=l;
                }
                l--;
                r++;
            }
        }
        ret=s.substr(st,ans);
        return ret;
    }
};