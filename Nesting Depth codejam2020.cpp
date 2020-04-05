#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long int

int main(){
    FastRead;
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        string s;
        cin>>s;
        string ans="";
        int lastd=s[0]-'0';
        for(int i=0;i<lastd;i++){
            ans+="(";
        }
        ans+=s[0];
        for(int i=1;i<s.length();i++){
            int x=s[i]-'0';
            if(x==lastd){
                ans+=s[i];
                //continue;
            }else if(x>lastd){
                int temp=x-lastd;
                for(int j=0;j<temp;j++){
                    ans+="(";
                }
                ans+=s[i];
                lastd=x;
            }else{
                int temp=lastd-x;
                for(int j=0;j<temp;j++){
                    ans+=")";
                }
                ans+=s[i];
                lastd=x;
            }
        }
        for(int i=0;i<lastd;i++){
            ans+=")";
        }
        cout<<"Case"<<" "<<"#"<<tc<<": "<<ans<<endl;
        tc++;
    }
}