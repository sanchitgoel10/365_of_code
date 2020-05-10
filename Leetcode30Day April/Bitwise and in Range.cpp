#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        
        while(m!=n){             //finding the first flip bit 
            m>>=1;
            n>>=1;
            count++;
        }
        
        return m<<count;
    }
};