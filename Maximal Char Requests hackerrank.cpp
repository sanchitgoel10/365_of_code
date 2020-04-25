#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
//#define int long long int
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

int32_t main(){
    FastRead;
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        if(int(str[i])<=90){
            str[i]=str[i]+32;
        }
    }
    int pre[n][26]; 
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            pre[i][j]=0;
        }
    }
    for (int i = 0; i < n; i++) {  
        pre[i][str[i] - 'a']++; 
        if (i) { 
            for (int j = 0; j < 26; j++) 
                pre[i][j] += pre[i - 1][j]; 
        } 
    } 
    
    int q;
    cin>>q;
    int l,r;
    while(q--){
        cin>>l>>r;
        for(int i=25;i>=0;i--){
            int times=pre[r][i];
            if(l)times-=pre[l-1][i];
            if(times>0){
                cout<<times<<endl;
                break;
            }
        }
        
    }
    return 0;
}

