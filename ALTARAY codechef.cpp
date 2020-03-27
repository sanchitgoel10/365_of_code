#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=n-1;i>=0;i--){
	        cin>>a[i];
	    }
	    int ans[n]={0};
	    int p=a[0];
	    ans[0]=1;
	    for(int i=1;i<n;i++){
	        if(p>=0){
	            if(a[i]<0){
	                ans[i]=ans[i-1]+1;
	            }else{
	                ans[i]=1;
	            }
	        }else{
	            if(a[i]>=0){
	                ans[i]=ans[i-1]+1;
	            }else{
	                ans[i]=1;
	            }
	        }
	        p=a[i];
	    }
	    for(int i=n-1;i>=0;i--){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
