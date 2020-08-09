class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        int i=1;
        while(i!=n){
            string old=s;
            s=old+"1";
            for(int i=old.size()-1;i>=0;i--){
                s+=old[i]=='1'?"0":"1";
            }
            i++;
        }
        k--;
        return s[k];
    }
};