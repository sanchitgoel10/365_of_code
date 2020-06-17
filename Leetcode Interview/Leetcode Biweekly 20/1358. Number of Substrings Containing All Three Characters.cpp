class Solution {
public:
    int numberOfSubstrings(string s) {
        int sz=s.size();
        int l=0;
        int cnt=0;
        unordered_map<char,int> m;
        for(int r=0;r<sz;r++){        //sliding window b/t l and r 
            m[s[r]]++; 
            while(m.size()==3){    //jab tak possible hai
                cnt+=sz-r;        //m.size==3 matlab 3 char aa gaye matlab iske aage ki saari ek baar isko include karke ban sakti hai
                m[s[l]]--;        //left side se char kam kara 
                if(m[s[l]]==0){
                    m.erase(s[l]); //particular char khatam ho gaya
                }
                l++;   //window aage badhi 
            }
        }
        return cnt;
    }
};