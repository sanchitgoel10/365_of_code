#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/*minInsertions(str[l+1…..h-1]) if str[l] is equal to str[h]
min(minInsertions(str[l…..h-1]), minInsertions(str[l+1…..h])) + 1 otherwise
*/


int main() {
	// your code goes here
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.length();
	    int dp[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            dp[i][j]=0;
	        }
	    }

	    for(int i=n;i>=1;i--){
	        int k=0;
	        int l=n-i;
	        for(int j=i;j>=1;j--){
	            if(k==l){
	                dp[k][l]=0;          //1 letter string 
	            }else if(k==l-1){        //2 letter string
	                if(s[k]==s[l]) dp[k][l]=0;
	                else dp[k][l]=1;
	            }else{                  //else
	                if(s[k]==s[l]){
	                    dp[k][l]=dp[k+1][l-1];
	                }else{
	                    dp[k][l]=min(dp[k][l-1],dp[k+1][l])+1;
	                }
	            }
	            k++;
	            l++;
	        }
	    }
	    cout<<dp[0][n-1]<<endl;
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<n;j++){
	   //         cout<<dp[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	}
	return 0;
}
