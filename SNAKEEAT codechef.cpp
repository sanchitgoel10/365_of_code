#include<bits/stdc++.h>
using namespace std;
#define min(a,b) (a<b ? a : b)

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int q;
        cin>>q;
       vector<long long int> A;
        for(long long int i=0;i<n;i++){
            long long int a;
            cin>>a;
            
            A.push_back(a);
        }       
    sort(A.begin(),A.end());
    long long int k;
    long long int sum[n];
    sum[0]=A[0];
    for(long long int i=0;i<n;i++)
       sum[i]=sum[i-1]+A[i];
        for(long long int j=0;j<q;j++){
            cin>>k;
           
              vector<long long int>::iterator lower;
              lower=lower_bound(A.begin(),A.end(),k);
               long long int cur=lower-A.begin();
             
               if(cur==n) // if k is greater than last element in sorted array.
                  cur--;
               if(A[cur]>=k && cur>=0) // if A[cur] is the k or greater than k.
                  cur--;
               long long int ans=(n-1)-cur; // those elment who are greater than equal to k
              long long int l=0;
              long long int r=cur;// r is the index of element with A[r]<k, so start search
              // do bianry search on prefix sum array to get additional snake.
              // number of snake require <= available snake.
              while(r>l){
                 long long int mid=(l+r)/2;
                 //cout<<mid<<endl;
                 if(k*(cur-mid)-(sum[cur]-sum[mid]) <=mid+1){
                    r=mid;
                 }
                 else{
                    l=mid+1;
                 }
              }
              
                 cout<<ans+cur-r;cout<<endl;
               }
               
           
           
        }
    
}