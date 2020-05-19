class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int ans=0;
        for(auto i:S){
            if(i=='('){
                s.push('(');
            }else{
                if(!s.empty())s.pop();
                else ans++;
            }
        }
        return s.size()+ans;
    }
};