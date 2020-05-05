#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int i=0;
        while(num){
            if(!(num&1)){
                ans+=(1<<i);
            }
            i++;
            num/=2;
        }
        return ans;
    }
};