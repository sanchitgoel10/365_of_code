#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define set set<int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)
#define w(t) int t;cin>>t;while(t--)

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    int*arr = new int[n];
    For(i,0,n)cin>>arr[i];
    int el1=-1,el2=-1,el1c=0,el2c=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el1){
            el1c++;
        }
        else if(arr[i]==el2){
            el2c++;
        }
        else if(el1c==0){
            el1=arr[i];
            el1c++;
        }
        else if(el2c==0){
            el2=arr[i];
            el2c++;
        }else{
            el1c--;
            el2c--;
        }
    }
    int c1=0,c2=0;
    int flag=0;
    if(el1c>0){
        For(i,0,n){
            if(arr[i]==el1){
                c1++;
            }
        }
        if(c1>n/3){
            cout<<el1<<" ";
            flag=1;
        }
    }
    if(el2c>0){
        For(i,0,n){
            if(arr[i]==el2){
                c2++;
            }
        }
        if(c2>n/3){
            cout<<el2<<" ";
            flag=1;
        }
    }
    if(flag==0){
        cout<<"No Majority Elements";
    }

	return 0;
}

