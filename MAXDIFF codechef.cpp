#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int w[n];
	    for(int i=0;i<n;i++){
	        cin>>w[i];
	    }
	    sort(w,w+n);
	    int l=0,m=0,v=0,b=0;
	    int md;
	    for(int i=0;i<k;i++){
	        l+=w[i];
	    }
	    for(int i=k;i<n;i++){
	        v+=w[i];
	    }
	    md=abs(v-l);
	    for(int i=n-k;i<n;i++){
	        m+=w[i];
	    }
	    for(int i=0;i<n-k;i++){
	        b+=w[i];
	    }
	    md=max(abs(b-m),md);
	    cout<<md<<endl;
	}
	return 0;
}
