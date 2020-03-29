#include<bits/stdc++.h>
using namespace std;
//Read the analysis please
int main(){
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxd=-1;
        for(int i=0;i<n-1;i++){
            int d=a[i+1]-a[i];
            maxd=max(maxd,d);
        }
        
        int l=1;
        int r=maxd;
        int ans;
        while(l<=r){
            int m=l+(r-l)/2;
            int tempk=0; //number of included sessions 
            int sess=a[0];
            int i=1;
            while(i<n){
                if(sess+m<a[i]){
                    sess=sess+m;
                    tempk++;
                }else{
                    sess=a[i];
                    i++;
                }
            }
            if(tempk>k){
                l=m+1;
            }else{
                ans=m;
                r=m-1;
            }
        }
        
        cout<<"Case"<<" "<<"#"<<tc<<":"<<" "<<ans<<endl;
        tc++;
    }
}