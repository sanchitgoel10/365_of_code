#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            cin>>v[i].second;
        }
        sort(v.begin(),v.end());
        vector<int> vd;           // vector containing different bands 
        int total=0;
        for(int i=0;i<n;i++){
            if(i==0 || (v[i].first>v[i-1].first)){
                vd.push_back(v[i].second);
            }else{
                total+=v[i].second;        // total minutes after we set first m bands in first m places
            }
        }
        sort(vd.begin(),vd.end());
        int m=vd.size();
        //for(int i=0;i<m;i++) cout<<vd[i];
        int ans=total*m;           // ans for songs after first different bands are played
        //cout<<ans<<endl;
        for(int i=1;i<=m;i++){
            int temp=vd[i-1]*i;
            //cout<<temp<<endl;
            ans=ans+temp;
            //cout<<ans<<endl;
        }
        
        cout<<ans<<endl;
    }
    
	return 0;
}
