#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

class trainer{
    public:
    int arrival;
    int teach;
    int sad;
};

bool cmp(trainer t1,trainer t2){
    return t1.arrival<t2.arrival;
}

int32_t main(){
    FastRead;
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        trainer arr[n];
        For(i,0,n){
            cin>>arr[i].arrival;
            cin>>arr[i].teach;
            cin>>arr[i].sad;
        }
        sort(arr,arr+n,cmp);
        int ans=0;
        priority_queue<pii> P;
        int j=0;
        For(i,1,d+1){
            while(arr[j].arrival==i && j<n){     //add to PQ all the trainers of that day
                P.push(mp(arr[j].sad,j));        //a dd sadness and index of trainer
                j++;
            }
            if(!P.empty()){
                auto ind=P.top();
                if(arr[ind.ss].teach>1){         //if he has more than one lec just reduce lecs
                    arr[ind.ss].teach--;         
                }else{
                    P.pop();                    //if only one lec then just pop it out
                }
            }
        }
        while(!P.empty()){
            ans+=(P.top().ff)*arr[P.top().ss].teach; // all the teachers left*their number of leectures
            P.pop();
        }
        cout<<ans<<endl;
        
    }
	return 0;
}

