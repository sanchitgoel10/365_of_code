#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        if(numRows==0)return ans;
        
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1)return ans;
        
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2)return ans;
        
        for(int i=3;i<=numRows;i++){
            vector<int> newtemp;
            newtemp.push_back(1);
            for(int i=0;i<temp.size()-1;i++){
                newtemp.push_back(temp[i]+temp[i+1]);
            }
            newtemp.push_back(1);
            ans.push_back(newtemp);
            temp=newtemp;
        }
        return ans;
    }
};