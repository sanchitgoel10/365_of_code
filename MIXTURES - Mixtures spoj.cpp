#include <bits/stdc++.h>
using namespace std;
#define int long long int

int arr[101];
int dp[1000][1000];


int sum(int i,int j){
    int ans=0;
    for(int k=i;k<=j;k++){
        ans+=arr[k];
        ans%=100;
    }
    return ans;
}

int solve(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}


int32_t main() {
	// your code goes here
	int n;
	while(cin>>n){
	    for(int i=0;i<n;i++) cin>>arr[i];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=n;j++){
	            dp[i][j]=-1;
	        }
	    }
	    int ans=solve(0,n-1);
	    cout<<ans<<endl;
	}
	return 0;
}
