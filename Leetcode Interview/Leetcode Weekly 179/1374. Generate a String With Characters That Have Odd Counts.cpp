class Solution {
public:
    string generateTheString(int n) {
        if(n%2==0){
            string s(n-1,'a');
            string ss(1,'b');
            return s+ss;
        }else{
            string s(n,'a');
            return s;
        }
    }
};