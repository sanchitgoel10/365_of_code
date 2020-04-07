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
#define for(i,a,b) for(int i=a;i<b;i++)

int32_t main(){
    FastRead;
    int n,w,l;
    cin>>n>>w>>l;
    vector<int> h(n);
    vector<int> r(n);
    for(i,0,n){
        cin>>h[i]>>r[i];
    }
    int s=0;
    int e=inf;
    int ans=inf;
    
    while(s<=e){
        int mid=(s+e)/2;
        //cout<<mid<<endl;
        int sum=0;
        for(i,0,n){
            int x=h[i]+r[i]*mid;
            if(x>=l){
                sum+=x;
            }
            if(sum>=w)break;        //This if condition is IMP VERY VERY IMP
            //total_cut may overflow. To fix this, return true as soon as total_cut exceeds W.
            
        }
        //cout<<sum<<endl;
        if(sum>=w){
            ans=min(ans,mid);
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
	return 0;
	
}

