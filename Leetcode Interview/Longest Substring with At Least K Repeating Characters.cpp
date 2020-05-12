#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> split(string s,char x){
        string temp="";
        vector<string> res;
        for(auto i:s){
            if(i==x){
                if(temp.size())res.push_back(temp);
                temp="";
            }else{
                temp+=i;
            }
        }
        if(temp.size())res.push_back(temp);
        return res;
    }
    
public:
    int longestSubstring(string S, int k) {
        int n=S.length();
        if(k==1)return n;
        if(k>n)return 0;
        
        int arr[26]={0};
        for(auto i:S){
            arr[i-'a']++;
        }
        char badchar='*';
        for(int i=0;i<26;i++){
            if(arr[i]!=0&&arr[i]<k){
                badchar=i+'a';
                break;
            }
        }
        if(badchar=='*')return n;
        vector<string> v=split(S,badchar);
        
        int ans=0;
        for(auto i:v){
            ans=max(ans,longestSubstring(i,k));
        }
        return ans;
    }
};