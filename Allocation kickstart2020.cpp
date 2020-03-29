#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n,b;
        cin>>n>>b;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(b>=a[i]){
                ans++;
                b-=a[i];
            }else{
                break;
            }
        }
        cout<<"Case"<<" "<<"#"<<tc<<":"<<" "<<ans<<endl;
        tc++;
    }
}