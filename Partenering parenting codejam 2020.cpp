#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long int

bool comp(pair<int, pair<bool, int> > p1,
			pair<int, pair<bool, int> > p2) {
 
	if (p1.first==p2.first) return p1.second.first > p2.second.first;
	return p1.first < p2.first;
 
}

int main(){
    FastRead;
    int t;
    cin>>t;
    int tc=1;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, pair<bool, int> > > v;
        bool ans[n+1];
        bool poss=true;
        
        for(int i=1;i<=n;i++){
            int si;int ei;
            cin>>si>>ei;
            v.push_back(make_pair(si, make_pair(0,i)));
            v.push_back(make_pair(ei, make_pair(1,i)));
        }
        sort(v.begin(),v.end(),comp);
        
        bool c=false,j=false;
        for(auto i:v){
            if(i.second.first==0){
                if(c==1 && j==1){
                    poss=false;
                    break;
                }
                if(c==0){
                    ans[i.second.second]=1;
                    c=1;
                }else if(j==0){
                    ans[i.second.second]=0;
                    j=1;
                }
            }else{
                if(ans[i.second.second]==0){
                    j=0;
                }else{
                    c=0;
                }
            }
            
        }
        
        string s="";
        if(poss==false){
            s="IMPOSSIBLE";
        }else{
            for(int i=1;i<=n;i++){
                if(ans[i]){
                    s+="C";
                }else{
                    s+="J";
                }
            }
        }
        cout<<"Case"<<" "<<"#"<<tc<<": "<<s<<endl;
        tc++;
    }
}