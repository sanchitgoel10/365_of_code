#include <bits/stdc++.h>
using namespace std;

int min_l(int n){
    if(n==0){
        return 0;
    }
    return (n+1+min_l(n/2)+min_l(n-(n/2)-1));
}
int max_l(int n){
    if(n==0){
        return 0;
    }
    return (n+1+max_l(n-1));
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int ans;
	    
	    int len=min_l(n);
	    
	    if(m<len){
	        ans=-1;
	        cout<<ans<<endl;
	        continue;
	    }
	    
	    len=max_l(n);
	    
	    if(len>=m){
	        ans=0;
	    }else{
	        ans=m-len;
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
