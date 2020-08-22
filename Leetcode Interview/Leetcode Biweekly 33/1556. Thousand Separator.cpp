class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0)return "0";
        string s="";
        int dcount=0;
        while(n){
            int d=n%10;
            s+=to_string(d);
            dcount++;
            if(dcount%3==0)s+='.';
            n/=10;
        }
        reverse(s.begin(),s.end());
        if(s[0]=='.')return s.substr(1);
        return s;
    }
};