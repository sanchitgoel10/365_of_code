class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        vector<string> v(numRows);
        int n=s.length();
        int i=0;
        int mid=numRows-2;    //bich ka zigzag wala pattern me kitne letters hai 
        while(i<n){
            for(int j=0;j<numRows&&i<n;j++){
                v[j]+=s[i];
                i++;
            }
            int j=numRows-2;
            int count=1;
            while(count<=mid&&i<n){
                v[j]+=s[i];
                j--;
                i++;
                count++;
            }
        }
        string res="";
        for(auto i:v){
            res+=i;
        }
        return res;
    }
};