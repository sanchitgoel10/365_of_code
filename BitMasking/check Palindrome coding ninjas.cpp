#include <bits/stdc++.h>
bool CheckPalindrome(long num) {
	string s="";
    while(num){
        if(num&1){
            s+="1";
        }else{
            s+='0';
        }
        num/=2;
    }
    int l=0,r=s.length()-1;
    int f=0;
    while(l<=r){
        if(s[l]!=s[r]){
            f=1;
            break;
        }
        l++;
        r--;
    }
    if(f==0)return true;
    return false;
}
