#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        //cout<<x<<endl;
        arr[x]+=1;
    }
    
    stack<char> t;
    string u="";
    for(int i=0;i<s.length();i++){
        t.push(s[i]);
        int x=s[i]-'a';
        int flag=0;
        for(int j=0;j<26;j++){
            if(j<x&&arr[j]>0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            string temp(1,s[i]);
            u.append(temp);
            arr[s[i]-'a']--;
            t.pop();
        }
        
    }
    while(!t.empty()){
        string temp(1,t.top());
        u.append(temp);
        t.pop();
    }
    cout<<u;
}