#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class stick{
    public:
    int len;
    int w;
};

bool cmp(stick a,stick b){
    if(a.len==b.len){
        a.w<b.w;
    }
    return a.len>b.len;
}

int main() {
	// your code goes here
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        vector<stick> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].len;
            cin>>v[i].w;
        }
        sort(v.begin(),v.end(),cmp);
        vector<stick> mach;
        mach.push_back(v[0]);
        for(int i=1;i<n;i++){
            int l=0;
            int r=mach.size()-1;
            while(l<=r){
                int m=(l+r)>>1;
                if(mach[m].w<v[i].w){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            if(l==mach.size()){
                mach.push_back(v[i]);
            }else{
                mach[l].len=v[i].len;
                mach[l].w=v[i].w;
            }
        }
        cout<<mach.size()<<endl;
	}
	return 0;
}