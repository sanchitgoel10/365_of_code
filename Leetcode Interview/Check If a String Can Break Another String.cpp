#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MAX_CHAR=26;
    void sortString(string &str) 
    { 
        int*charCount = new int[MAX_CHAR](); 

        for (int i=0; i<str.length(); i++) 
            charCount[str[i]-'a']++;     
        int ind=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<charCount[i];j++){
                str[ind]='a'+i;
                ind++;
            }
        }
    }
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        sortString(s1);
        sortString(s2);
        
        int i=0;
        for(;i<n;i++){
            if(s1[i]<s2[i])break;
        }
        if(i==n)return 1;
        i=0;
        for(;i<n;i++){
            if(s2[i]<s1[i])break;
        }
        if(i==n)return 1;
        return 0;
    }
};