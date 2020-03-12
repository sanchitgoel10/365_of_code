#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	   // int count[1001];
	    int *arr = new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        //count[arr[i]]++;
	    }
	    
	    
	    sort(arr,arr+n,greater<int>());
	    int ans=-1;
	    int h,b;
	    int c=0;
	    for(int i=0;i<n;i++){
	        if(c==2){
	            break;
	        }
	        if(arr[i]==arr[i+1]){
	            if(c==0){
	                h=arr[i];
	            }if(c==1){
	                b=arr[i];
	            }
	            c++;
	            i++;
	        }
	    }
	    if(c==2){
	        ans=h*b;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
