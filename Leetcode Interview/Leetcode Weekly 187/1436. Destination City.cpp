class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,bool> m;
        for(auto p:paths){
            m[p[0]]=0;
        }
        for(auto p:paths){
            if(!m.count(p[1]))return p[1];
        }
        return "";
    }
};