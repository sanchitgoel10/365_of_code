#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true){
		int n;
		cin>>n;
		if(n==-1) break;
		int a[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%n!=0){
			cout<<-1<<endl;
			continue;
		}else{
			int avg=sum/n;
			for(int i=0;i<n;i++){
				a[i]-=avg;
			}
			for(int i=1;i<n;i++){
				a[i]+=a[i-1];
			}
			int ans=0;
			for(int i=0;i<n;i++){
				ans=max(ans,abs(a[i]));
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}