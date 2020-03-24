#include <bits/stdc++.h>
using namespace std;

class cust{
    public:
    int s,e,p;
};

bool comp1(cust a,cust b){  // sorting function that sorts according to room, if room is same then end time
    
    if(a.p==b.p){
        return a.e<b.e;
    }else{
        return a.p<b.p;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    if(n==0){
	        cout<<0<<endl;
	        continue;
	    }
	    vector<cust> v(n);
	    for(int i=0;i<n;i++){
	        cust c;
	        cin>>c.s;
	        cin>>c.e;
	        cin>>c.p;
	        v[i]=c;
	    };
	    sort(v.begin(),v.end(),comp1);
	    int ans=1;
	    int i=0;
	    int lastroom=v[0].p;  //  the last room that we computed our ans on
	    for(int j=1;j<n;j++){
	        if(v[j].p!=lastroom){  // if the new room is different then just assign the cust
	            ans++;
	            lastroom=v[j].p;
	            i=j;               // VERY IMP for every new room this is the first cust
	        }else{
	            if(v[j].s>=v[i].e){
	                i=j;
	                ans++;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
