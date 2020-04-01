#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


// please do this question carefully


class doll{
	public:
	int width;
	int height;
	
};

bool cmp(doll d1,doll d2){        //sorting according to weight in decresing but if same weight then height in increasing 
    if(d1.width==d2.width){
        return d1.height<d2.height;
    }
    return d1.width>d2.width;
}

int main() {
	// your code goes here
	FastRead;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<doll> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i].width;
			cin>>v[i].height;
			//cout<<v[i].height;
		}
		sort(v.begin(),v.end(),cmp);
// 		for(int i=0;i<n;i++){
// 		    cout<<v[i].width<<" "<<v[i].height<<endl;
// 		}
		
		vector<doll> nest;     //different available dolls available for nesting ie putting dolls inside it
		nest.push_back(v[0]);
		
		for(int i=1;i<n;i++){
		    int l=0;
		    int r=nest.size()-1;
		    
		    while(l<=r){               //binary search to find the closest to height possible for putting dolls
		        int m=(l+r)>>1;
		        if(nest[m].height<=v[i].height){
		            l=m+1;
		        }else{
		            r=m-1;
		        }
		    }
		    if(l==nest.size()){
		        nest.push_back(v[i]);
		    }else{
		        nest[l].width=v[i].width;
		        nest[l].height=v[i].height;
		    }
		}
		cout<<nest.size()<<endl;
		
		
	}
	
	
	return 0;
}