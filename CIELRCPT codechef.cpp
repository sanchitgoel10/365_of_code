#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int price[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
	while(t--){
	    int n;
	    cin>>n;
	    int count=0;
	    int i=11;
	    while(n!=0){
	        if(n>=price[i]){
	            n-=price[i];
	            count++;
	        }else{
	            i--;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
