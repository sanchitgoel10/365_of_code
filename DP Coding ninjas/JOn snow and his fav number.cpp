#include <bits/stdc++.h>
using namespace std;
int freq[2][1024];


//hint video dekhio coding ninjas par

int main()
{
	int n,k,temp,x,ma=0;
    cin>>n>>k>>x;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        ma=max(ma,temp);
        ma=max(ma,temp^x);
        freq[0][temp]++;
        freq[1][temp]++;
    }
    ma=min(ma,1023);
    
    for(int i=0;i<k;i++)
    {
        int a=0;                    
        for(int j=0;j<=ma;j++)
        {
            if(freq[0][j]==0)
                continue;
            if(a%2==0)
            {
                int p=(freq[0][j]+1)/2;
                freq[1][(j^x)]+=p;
                freq[1][j]-=p;
            }else{
                int p=(freq[0][j])/2;
                freq[1][(j^x)]+=p;
                freq[1][j]-=p;
            }
            a+=freq[0][j];  
        }
        for(int j=0;j<=ma;j++){
           freq[0][j]=freq[1][j]; 
        }
             
    }
    int max,min;
    for(int i=ma;i>=0;i--){
        if(freq[0][i]>0) {
            max=i;
            break;
        }     
    }
     cout<<max<<" ";   
    for(int i=0;i<ma;i++){
         if(freq[0][i]>0){
             min=i;
             break;
         }
    }
      cout<<min;
    
}