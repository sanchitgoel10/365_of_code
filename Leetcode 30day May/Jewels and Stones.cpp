#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> m;
        for(auto i:J){
            m[i]=1;
        }
        int ans=0;
        for(auto i:S){
            if(m.count(i))ans++;
        }
        return ans;
    }
};