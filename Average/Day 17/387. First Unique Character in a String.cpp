#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(auto i:s){
            arr[i-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']==1)return i;
        }
        return -1;
    }
};