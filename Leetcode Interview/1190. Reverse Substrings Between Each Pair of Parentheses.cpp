class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        vector<int> open;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open.push_back(ans.length());
            }else if(s[i]==')'){
                int j=open.back();
                open.pop_back();
                reverse(ans.begin()+j,ans.end());
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};