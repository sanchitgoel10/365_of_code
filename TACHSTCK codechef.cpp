#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,d;
    cin>>n>>d;
    long long  *arr=new long long[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    long long ans=0;
    for(long long i=1;i<n;){
        if(arr[i]-arr[i-1]<=d){
            ans++;
            i+=2;
        }else{
            i++;
        }
    }
    cout<<ans;
	return 0;
}
