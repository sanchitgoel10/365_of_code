class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ps=p.size();
        int ss=s.size();
        vector<int> pc(26,0),sc(26,0),res;
        if(ps>ss)return res;
        
        for(int i=0;i<ps;i++){
            pc[p[i]-'a']++;
            sc[s[i]-'a']++;
        }
        if(pc==sc)res.push_back(0);
        
        for(int i=ps;i<ss;i++){
            sc[s[i]-'a']++;
            sc[s[i-ps]-'a']--;
            if(sc==pc)res.push_back(i-ps+1);
        }
        return res;
    }
};