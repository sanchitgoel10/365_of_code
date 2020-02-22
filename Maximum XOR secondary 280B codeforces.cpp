#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long arr[n];
    for(int i;i<n;i++){
        cin>>arr[i];
    }
    stack<long long int> s;
    long long int ans=-1;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        long long int x=arr[i];
        if(x<s.top()){
            ans=max(ans,(x xor s.top()));
        }else{
            while(!s.empty()&&x>s.top()){
                ans=max(ans,(x xor s.top()));
                s.pop();
            }
            if(!s.empty()){
                ans=max(ans,(x xor s.top()));
            }
        }
        s.push(x);
    }
    cout<<ans;
}