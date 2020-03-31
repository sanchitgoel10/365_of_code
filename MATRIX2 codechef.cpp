#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



int main() {
	// your code goes here
	FastRead;
	int n,m;
	cin>>n>>m;
	int mat[n][m];
	for(int i=0;i<n;i++){
	    string s;
	    cin>>s;
	    for(int j=0;j<s.length();j++){
	        mat[i][j]=s[j]-'0';
	        //cout<<mat[i][j]<<" ";
	    }
	    //cout<<endl;
	}
	
	for(int i=1;i<n;i++){
	    for(int j=1;j<m;j++){
	        if(mat[i][j]!=0){
	            mat[i][j]=min(mat[i-1][j],mat[i-1][j-1])+1;
	        }
	    }
	}
	
	
	long long ans=0;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        ans+=mat[i][j];
	        //cout<<mat[i][j]<<" ";
	    }
	    //cout<<endl;
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}
