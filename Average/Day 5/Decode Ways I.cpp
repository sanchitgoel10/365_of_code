#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        int*arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=s[i]-'0';
        }
        int*dp=new int[n+1]();
        dp[0]=1;
        if(arr[0])
            dp[1]=1;
        for(int i=2;i<=n;i++){
            if(arr[i-1]>0)dp[i]=dp[i-1];
            if(arr[i-2]==1||(arr[i-2]==2&&arr[i-1]<7))dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};