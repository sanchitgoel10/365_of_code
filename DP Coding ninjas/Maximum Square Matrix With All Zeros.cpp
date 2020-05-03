#include<bits/stdc++.h>
using namespace std;
/*
3 3 
1 0 0 
0 0 0
0 0 0

*/



int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int mx=-1;
    int **dp = new int*[row];
    for(int i=0;i<row;i++){
    	dp[i]=new int[col];
        for(int j=0;j<col;j++){
            if(i==0||j==0){
                if(arr[i][j]==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=0;
                }
            }else{
                if(arr[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
            mx=max(dp[i][j],mx);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    return mx;
}