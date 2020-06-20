/*The idea is intuitive. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added. At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0. Append the result and terminate recursive calls when both m and n are zero.
*/
class Solution {
public:
    
    void add(vector<string>&ans,string s,int n,int m){
        if(n==0&&m==0){
            ans.push_back(s);
            return;
        }
        if(m>0){
            add(ans,s+')',n,m-1);
        }
        if(n>0){
            add(ans,s+'(',n-1,m+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        add(ans,"",n,0);
        return ans;
    }
};