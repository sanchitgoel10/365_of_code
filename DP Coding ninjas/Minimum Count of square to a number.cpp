
int minCount(int n){
    
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    
    for(int i=4;i<=n;i++){
        dp[i]=i;
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],1+dp[i-(j*j)]);
        }
    }
    return dp[n];
    
}