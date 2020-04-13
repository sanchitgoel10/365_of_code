#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

bool check(int mid,int arr[],int n, mii m){
    int h=-1;
    for(auto i:m){
        h=max(h,i.ss);
    }
    if(mid>h){
        return 0;
    }
    int left=h-mid;
    int inc=-1;
    if(left>0)inc=1;
    else inc=0;
    if(h>=mid && m.size()-1+inc>=mid){
        return 1;
    }
    return 0;
}

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int maxsize=n/2;
	    int arr[n];
	    mii m;
	    For(i,0,n){
	        cin>>arr[i];
	        if(m.find(arr[i])==m.end())m[arr[i]]=1;
	        else m[arr[i]]++;
	    }
	    if(n==1){
	        cout<<0<<endl;
	        continue;
	    }
	    int s=0,e=maxsize;
	    int ans=0;
	    while(s<=e){
	        int mid=(s+e)/2;
	        //cout<<mid<<endl;
	        if(check(mid,arr,n,m)){
	            ans=mid;
	            s=mid+1;
	        }else{
	            e=mid-1;
	        }
	    }
	    cout<<ans<<endl;
	    
	    
	}
	return 0;
}

