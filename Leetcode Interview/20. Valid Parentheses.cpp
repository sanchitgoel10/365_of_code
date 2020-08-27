class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for(auto c:S){
            if(!s.empty()){
                if(s.top()=='('&&c==')')s.pop();
                else if(s.top()=='{'&&c=='}')s.pop();
                else if(s.top()=='['&&c==']')s.pop();
                else s.push(c);
            }else{
                s.push(c);
            }
        }
        return s.size()?false:true;
    }
};