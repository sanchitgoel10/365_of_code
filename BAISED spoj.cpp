#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		int rank[n+1];
		rank[0]=-1;
		for(int i=0;i<n;i++){
			cin>>s;
			cin>>rank[i+1];
		}
		sort(rank,rank+n+1);
		long long int bad=0;
		for(int i=1;i<=n;i++){
			bad+=abs(rank[i]-i);
		}
		cout<<bad<<endl;
		
	}
	return 0;
}