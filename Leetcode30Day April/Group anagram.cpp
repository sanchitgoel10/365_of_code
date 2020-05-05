#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        
        string temp=strs[0];
        sort(temp.begin(),temp.end());
        map<string,vector<int>> m;
        m[temp].push_back(0);
        
        for(int i=1;i<strs.size();i++){
            string t=strs[i];
            sort(t.begin(),t.end());
            m[t].push_back(i);
        }
        for(auto i:m){
            vector<string> t;
            for(auto j:i.second){
                t.push_back(strs[j]);
            }
            v.push_back(t);
        }
        return v;
    }
};