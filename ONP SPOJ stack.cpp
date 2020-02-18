#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<char> v;
		stack<char> stack;
		int count=1;
		int i=1;
		while(count>0&&i<s.length()){
			if(s[i]=='('){
				count++;
			}
			else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
			    char temp=s[i];
				stack.push(temp);
			}
			else if(s[i]==')'){
				count--;
				v.push_back(stack.top());
				stack.pop();
			}
			else{
			    char temp1=s[i];
				v.push_back(temp1);
			}
			i++;
		}
		for(auto &i:v){
			cout<<i;
		}
		cout<<endl;
	}

	return 0;
}