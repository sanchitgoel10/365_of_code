class Solution {
public:
    string toGoatLatin(string S) {
        int acount=1;
        string lastword="";
        set<char> set={'a','e','i','o','u','A','E','I','O','U'};
        string add="ma";
        string ans="";
        for(int i=0;i<S.size();i++){
            if(S[i]==' '){
                string a(acount,'a');
                if(set.find(lastword[0])!=set.end()){
                    lastword+=add;
                    lastword+=a;
                    ans+=lastword;
                }else{
                    ans+=lastword.substr(1);
                    ans+=lastword[0];
                    ans+=add;
                    ans+=a;
                }
                ans+=" ";
                lastword="";
                acount++;
            }else{
                lastword+=S[i];
            }
        }
        string a(acount,'a');
        if(set.find(lastword[0])!=set.end()){
            lastword+=add;
            lastword+=a;
            ans+=lastword;
        }else{
            ans+=lastword.substr(1);
            ans+=lastword[0];
            ans+=add;
            ans+=a;
        }
        return ans;
    }
};