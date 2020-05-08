#include<bits/stdc++.h>
using namespace std;
#define pq priority_queue <int>


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        pq p;
        for(auto i:stones){
            p.push(i);
        }
        int x,y;
        while(p.size()>1){
            y=p.top();
            p.pop();
            x=p.top();
            p.pop();
            if(x!=y)p.push(y-x);
        }
        if(p.empty())return 0;
        else return p.top();
    }
};