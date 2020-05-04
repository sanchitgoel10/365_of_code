#include<bits/stdc++.h>
using namespace std;

int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
	int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){           //left se condition fullfill kari
        if(arr[i]>arr[i-1]){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=1;
        }
    }
    int ans=dp[n-1]; 
    for(int j=n-2;j>=0;j--){             //right se cond fulfill kari 
        if(arr[j]>arr[j+1]&&dp[j]<=dp[j+1]){
            dp[j]=dp[j+1]+1;
        }
        ans+=dp[j];
    }
    
    return ans;
}
