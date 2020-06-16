#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        int sizer=ransomNote.size();
        for(auto i:ransomNote){
            if(m.count(i)){
                m[i]++;
            }else{
                m[i]=1;
            }
        }
        int ans=0;
        for(auto i:magazine){
            if(m.count(i)){
                if(m[i]>0){
                    ans++;
                    m[i]--;
                }
            }
        }
        if(ans==sizer){
            return 1;
        }
        return 0;
    }
};