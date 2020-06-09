class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int c=0;
        for(auto i:t){
            if(c==n)return 1;
            if(i==s[c]){
                c++;
            }
        }
        if(c==n)return 1;
        return 0;
    }
};