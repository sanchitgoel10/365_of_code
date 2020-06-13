#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        
        double m=double(y2-y1)/double(x2-x1);
        //cout<<m;
        for(int i=2;i<coordinates.size();i++){
            int tx=coordinates[i][0];
            int ty=coordinates[i][1];
            
            if(double(ty-y1)/double(tx-x1)!=m)return 0;
        }
        return 1;
    }
};