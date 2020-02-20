#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    //cout<<s.length();
	    stack <int> st;
	    if(s[0]=='>'){
	        cout<<0<<endl;
	        continue;
	    }
	    //int count=1;
	    int ans=0;
	    int i=0;
	    st.push(0);
	    for(int i=1;i<s.length();i++){
	        if(s[i]=='<'){
	            st.push(0);
	        }
	        if(s[i]=='>'){
	            if(st.empty()){
	                break;
	            }
	            st.pop();
	        }
	        if(st.empty()){
	            ans=i+1;
	        }
	    }
	    cout<<ans<<endl;
	    
	}
	return 0;
}
