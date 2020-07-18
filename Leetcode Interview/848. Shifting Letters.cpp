class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n=shifts.size();
        shifts[n-1]=shifts[n-1]%26;         //ghum ke yahi aa jayega 
        for(int i=n-2;i>=0;i--){
            shifts[i]+=shifts[i+1];
            shifts[i]=shifts[i]%26;
        }
        for(int i=0;i<n;i++){
            //cout<<int(S[i])<<" "<<shifts[i]<<endl;
            int x=(S[i]-'a'+shifts[i])%26;
            S[i]=char(x+'a');
        }
        return S;
    }
};