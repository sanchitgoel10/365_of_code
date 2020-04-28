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

int next(vec arr,int i){
    return (i+arr[i]+arr.size())%arr.size();
}

bool cycle(vec arr){
    int n=arr.size();
    For(i,0,n){
        if(i==0)continue;
        int slow=i,fast=i;     //slow ek step  fast 2 step
        while(arr[slow]*arr[next(arr,slow)]>0&&   //these are conditions ki same direction rahe
              arr[fast]*arr[next(arr,fast)]>0&&
              arr[fast]*arr[next(arr,next(arr,fast))]>0){

                  slow=next(arr,slow);
                  fast=next(arr,next(arr,fast));

                  if(slow==fast){          //agar slow fast mile to hai cycle
                      if(slow==next(arr,i))break;  //len of cycle>1
                      return true;
                  }
              }

              slow=i;
              int v=arr[slow];
              while(v*arr[slow]>0){        //agar cycle is index se nhi hua to jaha jaha
                  arr[slow]=0;             //jump kara the waha se nhi hoga cycle
                  slow=next(arr,slow);
              }

    }
    return false;
}

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    vec arr;
    int x;
    For(i,0,n){
        cin>>x;
        arr.pb(x);
    }
    cout<<cycle(arr)<<endl;
	return 0;
}

