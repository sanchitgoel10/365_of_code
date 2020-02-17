#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1){
		int n;
		cin>>n;
		if(n==0)
			break;
		int arr[n];
		vector<int> v;
		queue<int> q;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			q.push(arr[i]);
		}
		stack<int> s;
		
		int k=1;
		while(!q.empty()){
			if(q.front()!=k){
				if(!s.empty()){
					if(s.top()==k){
						v.push_back(s.top());
						s.pop();
						k++;
					}else{
						s.push(q.front());
						q.pop();
					}
				}else{
					s.push(q.front());
					q.pop();
				}
			}else{
				k++;
				v.push_back(q.front());
				q.pop();
			}
		}
		while(!s.empty()){
			v.push_back(s.top());
			s.pop();
		}
		int flag=0;
		for(int i=0;i<n;i++){
			if(v[i]!=i+1){
				flag=1;
				//cout<<v[i]<<endl;
			}
		}
		if(flag==0){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}

	}
	return 0;
}