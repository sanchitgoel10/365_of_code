#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define set set<int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)
#define w(t) int t;cin>>t;while(t--)

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int rec(vector<string> v,string s,int i){
    if(i==v.size()){
        int freq[26]={0};

        For(k,0,s.length()){
            if(freq[s[k]-'a']==1)return 0;
            freq[s[k]-'a']++;
        }
        return s.length();
    }
    int op1=INT_MIN,op2=INT_MIN;
    if(s.length()+v[i].length()<=26){
        op1=rec(v,s+v[i],i+1);
    }
    op2=rec(v,s,i+1);
    return max(op1,op2);
}

int func(vector<string> v){
    string s="";
    return rec(v,s,0);
}

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    vector<string> v;
    string s;
    For(i,0,n){
        cin>>s;
        v.pb(s);
    }
    cout<<func(v)<<endl;
    
	return 0;
}

