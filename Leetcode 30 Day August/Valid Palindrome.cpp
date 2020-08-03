class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size())return 1;
        int i=0,j=s.size()-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(i<=j){
            if(!isalnum(s[i]))i++;
            else if(!isalnum(s[j]))j--;
            else{
                if(s[i]!=s[j]){
                    return 0;
                }
                i++;
                j--;
            }
        }
        return 1;
    }
};