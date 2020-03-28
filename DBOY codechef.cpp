#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// Coin change problem hai N times
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> h(n+1);
	    vector<int> k(n+1);
	    int max=-1;
	    for(int i=1;i<=n;i++){
	        cin>>h[i];
	        h[i]=h[i]*2;
	        if(h[i]>max) max=h[i];
	    }
	    for(int i=1;i<=n;i++) cin>>k[i];
	    int ans=0;
	    int dp[n+1][max+1];
	    dp[0][0]=0;
	    for(int j=1;j<=max;j++) dp[0][j]=10000000; // 1+IntMAx wali situation a sakti hai isliye 100000 aise lele number
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=max;j++){
	            dp[i][j]=dp[i-1][j];
	            if(k[i]<=j)
	            dp[i][j]=min(dp[i][j],1+dp[i][j-k[i]]);
	        }
	    }
	    for(int i=1;i<=n;i++){
	        int x=h[i];
	        //cout<<dp[n][x];
	        ans+=dp[n][x];
	    }
	    cout<<ans<<endl;
	    
	    
	}
	return 0;
}
