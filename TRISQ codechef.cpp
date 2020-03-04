#include <bits/stdc++.h>
using namespace std;
int B[10001];

void pre(){
    int x=1;
    
    for(int i=0;i<4;i++){
        B[i]=0;
    }
    for(int i=4;i<10001;i++){
        if(i%2==0){
           B[i]=B[i-1]+x;
           x++;
        }else{
            B[i]=B[i-1];
        }
    }
}



int main() {
	int t;
	cin>>t;
	pre();
	while(t--){
	    int n;
	    cin>>n;
	    cout<<B[n]<<endl;
	}
	return 0;
}
