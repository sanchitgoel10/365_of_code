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

int32_t main(){
	FastRead;
	string s;
    cin>>s;
    int n=s.length();
    int freq[26]={0};
    for(auto i:s){
        freq[i-'a']++;
    }
    bool* vis = new bool[26]();
    string ans;
    for(auto i:s){
        freq[i-'a']--;            //going to deal with character abhi ke abhi
        if(vis[i-'a'])continue;   //pehele hi deal kar chuke hai
        while(!ans.empty() &&i<ans.back() && freq[ans.back()-'a']>0){   //jab tak string ka last bada hai and aage aur hai waise tab tak delete karte jaa
            vis[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans.pb(i);
        vis[i-'a']=1;
    }
    cout<<ans<<endl;
	return 0;
}

