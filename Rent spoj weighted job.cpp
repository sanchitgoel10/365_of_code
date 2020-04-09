#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

class job{
    public:
    int s;
    int e;
    int p;
};

bool cmp(job j1,job j2){
    // if(j1.e==j2.e){
    //     j1.s<j2.s;
    // }
    return j1.e<j2.e;
}

int solve(job arr[],int n){
    
    sort(arr,arr+n,cmp);
    int *dp = new int[n];
    dp[0]=arr[0].p;
    for(int i=1;i<n;i++){
        int lncof=-1;
        int l=0;
        int h=i-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid].e<arr[i].s){
                lncof=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        if(lncof!=-1){
            dp[i]=max(dp[i-1],dp[lncof]+arr[i].p);
        }else{
            dp[i]=max(arr[i].p,dp[i-1]);
        }
    }
    
    int ans=dp[n-1];
    return ans;
    delete[] dp;
    
}

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        job arr[n];
        For(i,0,n){
            cin>>arr[i].s;
            int d;
            cin>>d;
            arr[i].e=arr[i].s+d;
            cin>>arr[i].p;
        }
        cout<<solve(arr,n)<<endl;
        
        
    }
	return 0;
}

