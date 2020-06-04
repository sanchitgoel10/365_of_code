class Solution {
public:
    string reformat(string s) {
        string digs="";
        string alps="";
        int dig=0;
        int alp=0;
        for(auto i:s){
            if(i>='0'&&i<='9'){
                dig++;
                digs+=i;
            }else{
                alp++;
                alps+=i;
            }
        }
        if(abs(dig-alp)>1)return "";


        string ans="";
        int i=0,j=0;
        int count=0;
        if(alp>=dig){
            count=1;
        }
        while(i<alps.size()||j<digs.size()){
            if(count%2==0){
                ans+=digs[j];
                j++;
            }else{
                ans+=alps[i];
                i++;
            }
            count++;
        }
        return ans;
    }
};