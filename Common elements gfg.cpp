#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vec vector<int>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vec A(n1),B(n2),C(n3);
        mii m;
        For(i,0,n1){
            cin>>A[i];
            if(m.find(A[i])==m.end())m[A[i]]=1;
        }
        mii m1;
        For(i,0,n2){
            cin>>B[i];
            if(m.find(B[i])!=m.end())m1[B[i]]=2;
        }
        For(i,0,n3){
            cin>>C[i];
            if(m1.find(C[i])!=m1.end())m1[C[i]]=3;
        }
        int flag=0;
        for(auto i:m1){
            //cout<<i.ff<<i.ss<<endl;
            if(i.ss==3){
                flag=1;
                cout<<i.ff<<" ";
            }
        }
        if(flag==0)cout<<-1<<" ";
        cout<<endl;
    }
	return 0;
}

