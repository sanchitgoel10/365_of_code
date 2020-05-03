#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    int *dp=new int[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    
    int ans=dp[n-1];
    delete [] dp;
    return ans;
}
