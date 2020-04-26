/*
Lets iterate over s == SSN2(W3(EE)W)E
remember r=0, c=0 (displacement at first ) stack have 1 already in it  and num=1
s[0]= 'S'   r=0+num =0+1=1 ,c=0 stack =(1)  num=1
s[1]='S'   r=1+1=2 ,c=0 stack (1)  num =1
s[2]='N'  r=2-num = 2-1 =1 c=0 stack (1) num=1
s[3]='2'  r=1,c=0   num=1*2=2  stack(1,2)  (ignore '('  )
s[5]='W'  r=1,c=0+num =0+2 =2 num =2 stack (1,2)
s[6]='3'  r=1,c=2   num=2*3=6 stack (1,2,6)  (ignore '(' )
s[8]='E'  r=1, c=2-num =2-6=-4  num=6 stack(1,2,6)
s[9]='E' r=1,c=-4-num=-10 num 6 stack(1,2,6)
s[10]=')'  r=1,c=-10 num =-10 stack (1,2) and we set num = stack.top() =2 so now num =2 
s[11]='W' r=1 c=-10+num  =-8 stack (1,2) num =2
s[12]=')'  r=1,c=-8  num =2 stack (1)  so set num =1 
s[13]= 'E' r=1 ,c=-8-1 =-9 num =1 stack (1)
So final position 1+r = 2   and 1+c = -8  ( because initial position was 1 1)
if c,r goes above 10^9 mod them or if they  goes below 0 add 10^9


*/

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
#define mod 1000000000
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
	int tc=1;
	w(t){
	    string s;
	    cin>>s;
	    int sx=1;
	    int sy=1;
	    int r=0,c=0;
	    int num=1;
	    stack<int> stk;
	    stk.push(1);
	    For(i,0,s.length()){
	        if(s[i]>='2'&&s[i]<='9'){
	            int d=s[i]-'0';
	            num=num*d%mod;
	            stk.push(num);
	        }
	        if(s[i]=='(')continue;
	        if(s[i]==')'){
	            stk.pop();
	            num=stk.top();
	        }
	        if(s[i]=='N'){
	            r-=num;
	            if(r<0)r+=mod;
	        }
	        if(s[i]=='S'){
	            r+=num;
	            r%=mod;
	        }
	        if(s[i]=='E'){
	            c+=num;
	            c%=mod;
	        }
	        if(s[i]=='W'){
	            c-=num;
	            if(c<0)c+=mod;
	        }
	    }
	    
	    
	    cout<<"Case"<<" "<<"#"<<tc<<":"<<" "<<sy+c<<" "<<sx+r<<endl;
        tc++;
	}
	return 0;
}

