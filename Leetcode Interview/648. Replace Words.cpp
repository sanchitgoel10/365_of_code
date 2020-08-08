class Solution {
public:
     string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> dics;
        int max_len = 0;
        for(string s: dict){
            dics.insert(s);
            max_len = max(max_len,(int)s.size());
        } 
        string ans = "";
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            int len = word.size();
            bool flag = 0;
            for(int i=1;i<=min(len,max_len);++i){
                if(dics.find(word.substr(0,i))!=dics.end()){
                    ans += " "+word.substr(0,i);
                    flag = 1;
                    break;
                } 
            }
            if(!flag) ans+=" "+word;
        } 
        return ans.substr(1);
    }
};