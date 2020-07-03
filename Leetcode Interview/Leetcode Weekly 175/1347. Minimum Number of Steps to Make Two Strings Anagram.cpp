class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        int ans=0;
        for(auto c:t){
            if(m[c]==1){
                m.erase(c);
            }else if(m[c]>1){
                m[c]--;
            }else{
                ans++;
            }   
        }
        return ans;
    }
};