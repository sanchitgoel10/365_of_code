class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> m1,m2;
        for(auto c:s){
            m1[c]++;
        }
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            m2[s[i]]++;
            m1[s[i]]--;
            if(m1[s[i]]==0)m1.erase(s[i]);
            if(m1.size()==m2.size())ans++;
        }
        return ans;
    }
};