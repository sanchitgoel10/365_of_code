#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            if(s.find(n)!=s.end()){
                return 0;
            }else{
                s.insert(n);
            }
            int sum=0;
            while(n){
                int d=n%10;
                sum+=(d*d);
                n/=10;
            }
            n=sum;
        }
        return 1;
    }
};