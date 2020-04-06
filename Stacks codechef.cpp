#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        if(v.size()==0){
	            v.push_back(arr[i]);
	            continue;
	        }
	        auto it=upper_bound(v.begin(),v.end(),arr[i]);
	        //cout<<it-v.begin()<<endl;
	        if(it!=v.end()){
	           v[it-v.begin()]=arr[i]; 
	        }else{
	            v.push_back(arr[i]);
	        }
	    }
	    cout<<v.size()<<" ";
	    for(int i=0;i<v.size();i++){
	        cout<<v[i]<<" "; 
	    }
	    cout<<endl;
	}
	return 0;
}
