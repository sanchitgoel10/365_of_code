#include <bits/stdc++.h>
using namespace std;

int func(int s,int t,int i,int d){
    
    cout<<s<<" "<<t<<endl;
    if(s==i&&t==i){
        return d;
    }
    int mid=(s+t)/2;
    
    if(i>mid){
        func(mid+1,t,i,d+1);
    }else{
        func(s,mid,i,d+1);
    }
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int s,t,i;
	    cin>>s>>t>>i;
	    if(i<s||i>t){
	        cout<<-1<<endl;
	        continue;
	    }
	    int d=1;
	    int ans=func(s,t,i,d);
	    cout<<ans<<endl;
	}
	return 0;
}
