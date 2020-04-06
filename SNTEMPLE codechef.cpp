#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>



int32_t main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    int s=0;
	    for(int i=0;i<n;i++) cin>>v[i],s+=v[i];
	    int l[n]={0};
	    int r[n]={0};
	    int k=0;
	    for(int i=0;i<n;i++){
	        if(v[i]>=k+1){
	            k++;
	        }else{
	            k=v[i];
	        }
	        l[i]=k;
	    }
	    k=0;
	    for(int i=n-1;i>=0;i--){
	        if(v[i]>=k+1){
	            k++;
	        }else{
	            k=v[i];
	        }
	        r[i]=k;
	    }
	    int m=-1;
	    for(int i=0;i<n;i++){
	        m=max(m,min(l[i],r[i]));
	    }
	    cout<<s-m*m<<endl;       //s-m*m operations, because the sum of heights in magic(m)magic(m) is m^2
	    
	}
	return 0;
}
