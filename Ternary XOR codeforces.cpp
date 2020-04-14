#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define vec vector<int>
#define pq priority_queue <int>
#define pqr priority_queue <int, vector<int>, greater<int>>
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    string s;
	    cin>>s;
	    string a="1";
	    string b="1";
	    int c=0;
	    for(int i=1;i<x;i++){
	       if(c==0){
	          if(s[i]=='2'){
	               a+='1';
	               b+='1';
	           }else if(s[i]=='0'){
	               a+='0';
	               b+='0';
	           }else{
	                a+='1';
	                b+='0';
	                c=1;
	           } 
	       }else{
	           if(s[i]=='2'){
	               a+='0';
	               b+='2';
	           }else if(s[i]=='0'){
	               a+='0';
	               b+='0';
	           }else{
	                a+='0';
	                b+='1';
	           } 
	       }
	       
	    }
	    cout<<a<<endl;
	    cout<<b<<endl;
	}
	return 0;
}