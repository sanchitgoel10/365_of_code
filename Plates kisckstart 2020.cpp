#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n,k,p;
        cin>>n>>k>>p;
        int mat[n+1][k+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                cin>>mat[i][j];
            }
        }
        int sum[n+1][k+1];
        memset(sum,0,sizeof(sum)); //sum[i][x] denote the sum of first x plates from stack i.
        for(int i=1;i<=n;i++){
            sum[i][1]=mat[i][1];   
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=k;j++){
                sum[i][j]=sum[i][j-1]+mat[i][j];
            }
        }
        
        int dp[n+1][p+1];  //dp[i][j] which denotes the maximum sum that can be obtained using the first i stacks when we need to pick j plates in total.
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=p;j++){
                for(int x=0;x<=min(j,k);x++){
                    dp[i][j]=max(dp[i][j],sum[i][x]+dp[i-1][j-x]);
                }
            }
        }
        
        cout<<"Case"<<" "<<"#"<<tc<<":"<<" "<<dp[n][p]<<endl;
        tc++;
    }
}