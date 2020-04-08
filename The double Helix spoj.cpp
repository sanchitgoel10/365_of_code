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

int32_t main(){
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        vector<int> v1(n);
        For(i,0,n)cin>>v1[i];
        int m;
        cin>>m;
        vector<int> v2(m);
        For(i,0,m)cin>>v2[i];
        
        int seg1=0;
        int seg2=0;
        int i=0,j=0;
        int ans=0;
        while(i<n && j<m){
            if(v1[i]<v2[j]){
                seg1+=v1[i++];
            }else if(v1[i]>v2[j]){
                seg2+=v2[j++];
            }else{
                ans+=max(seg1,seg2);
                ans+=v1[i];
                //cout<<ans<<endl;
                seg1=0;seg2=0;
                i++;
                j++;
            }
        }
        while(i<n) seg1+=v1[i++];
        while(j<m) seg2+=v2[j++];
        //cout<<seg1<<" "<<seg2<<endl;
        ans+=max(seg1,seg2);
        cout<<ans<<endl;
        
    }
	return 0;
}

