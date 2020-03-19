#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int l=s.length();
	    for(int i=l-4;i>=0;i--){
	        if(!(s[i]=='C' || s[i]=='?'))continue;
	        if(!(s[i+1]=='H' || s[i+1]=='?'))continue;
	        if(!(s[i+2]=='E' || s[i+2]=='?'))continue;
	        if(!(s[i+3]=='F' || s[i+3]=='?'))continue;
	        s[i]='C';
	        s[i+1]='H';
	        s[i+2]='E';
	        s[i+3]='F';
	        
	    }
	    for(int i=0;i<l;i++){
	        if(s[i]=='?'){
	            s[i]='A';
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}
