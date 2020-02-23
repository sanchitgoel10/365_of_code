#include <bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	while(1){
		string s;
		cin>>s;
		if(s[0]=='-'){
			break;
		}
		stack<char> st;
		for(int i=0;i<s.length();i++){
			if(st.empty()){
				st.push(s[i]);
			}else{
				if(st.top()=='{'&&s[i]=='}'){
					st.pop();
				}else{
					st.push(s[i]);
				}
			}
		}
		double o=0,c=0;
		while(!st.empty()){
			if(st.top()=='{'){
				o+=1;
			}else{
				c+=1;
			}
			st.pop();
		}
	//	cout<<o<<" "<<c<<endl;
		int ans=ceil(o/2)+ceil(c/2);
	
		cout<<t<<". "<<ans<<endl;
		t++;
	}
	return 0;
}