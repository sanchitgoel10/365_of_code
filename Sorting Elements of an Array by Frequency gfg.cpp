#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vec  vector<int> 
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

class freq{
    public:
    int f;
    int num;
};

bool cmp(freq f1,freq f2){
    if(f1.f==f2.f){
        return f1.num<f2.num;
    }
    return f1.f>f2.f;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vec v(n);
        mii m;
        For(i,0,n){
            cin>>v[i];
            if(m.find(v[i])==m.end())m[v[i]]=1;
            else m[v[i]]++;
        }
        vector<freq> F;
        for(auto i:m){
            freq x;
            x.f=i.ss;
            x.num=i.ff;
            F.pb(x);
        }
        sort(F.begin(),F.end(),cmp);
        
        For(i,0,F.size()){
            int number=F[i].num;
            int times=F[i].f;
            while(times!=0){
                cout<<number<<" ";
                times--;
            }
        }
        cout<<endl;
    }
	return 0;
}

