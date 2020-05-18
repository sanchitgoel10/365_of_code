class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()==0&&s2.size()==0)return 0;
        if(s2.size()!=0&&s1.size()==0)return 1;
        if(s1.size()>s2.size())return 0;
        
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(v1==v2)return 1;
        for(int i=s1.size();i<s2.size();i++){
            v2[s2[i]-'a']++;
            v2[s2[i-s1.size()]-'a']--;
            if(v1==v2)return 1;
        }
        return 0;
    }
};