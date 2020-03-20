#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int start=0,end=0;
	    int s=0;
	    long long curr_sum=0;
	    long long best_sum=0;
	    for(int i=0;i<n;i++){
	        curr_sum+=arr[i];
	        if(best_sum<curr_sum){
	            best_sum=curr_sum;
	            start=s;
	            end=i;
	        }
	        if(curr_sum<0){
	            curr_sum=0;
	            s=i+1;
	        }
	    }
	    cout<<start<<endl;
	    cout<<best_sum<<endl;
	    cout<<end<<endl;
	}
	return 0;
}
