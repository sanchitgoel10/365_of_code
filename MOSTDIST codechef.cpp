
#include<bits/stdc++.h>
#define t_suman ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define pll pair<ll,ll>
#define VP vector< pll >
#define VLL vector< ll >
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(ll (i) = (a); (i) < (b); (i)++)
#define rrep(i,a,b) for(ll (i) = (a); (i) > (b); (i)--)
#define all(v) (v).begin(),(v).end()
#define FF first
#define SS second
#define in insert
#define out erase
#define MOD 1e18
#define MAX 1000005
using namespace std;
 
struct point
{
	ll x,y,num;
	point(ll x,ll y,ll n):x(x),y(y),num(n){}
	//point(){}
};

struct compare1{
	bool operator()(const point& p1,const point& p2){
		return p1.x+p1.y<p2.x+p2.y;
	}
};
struct compare2{
	bool operator()(const point& p1,const point& p2){
		return p1.x-p1.y<p2.x-p2.y;
	}
};
struct compare3{
	bool operator()(const point& p1,const point& p2){
		return -p1.x+p1.y<-p2.x+p2.y;
	}
};
struct compare4{
	bool operator()(const point& p1,const point& p2){
		return -p1.x-p1.y<-p2.x-p2.y;
	}
};


int main() {
	ll t;
	cin>>t;
	priority_queue<point,vector<point>,compare1> pq1;
	priority_queue<point,vector<point>,compare2> pq2;
	priority_queue<point,vector<point>,compare3> pq3;
	priority_queue<point,vector<point>,compare4> pq4;
	ll ans=0,i=1;
	map<ll,bool> m1;
	while(t--){
		char ch;
		cin>>ch;
			if(ch=='+'){
				ll x,y;
				cin>>x>>y;
				x=x^ans;
				y=y^ans;
				point temp=point(x,y,i++);
				pq1.push(temp);
				pq2.push(temp);
				pq3.push(temp);
				pq4.push(temp);
			}
			else if(ch=='-'){
				ll n;
				cin>>n;
				n=n^ans;
				m1[n]=1;
			}
			else{
				ll x,y;
				cin>>x>>y;
				x=x^ans;
				y=y^ans;
				while(m1[pq1.top().num]==1){
					pq1.pop();
				}
				while(m1[pq2.top().num]==1){
					pq2.pop();
				}
				while(m1[pq3.top().num]==1){
					pq3.pop();
				}
				while(m1[pq4.top().num]==1){
					pq4.pop();
				}


				ans=-1;
				if(!pq1.empty()){
					ans=max(ans,pq1.top().x+pq1.top().y-x-y);
				}
				if(!pq2.empty()){
					ans=max(ans,pq2.top().x-pq2.top().y-x+y);
				}
				if(!pq3.empty()){
					ans=max(ans,-pq3.top().x+pq3.top().y+x-y);
				}
				if(!pq4.empty()){
					ans=max(ans,-pq4.top().x-pq4.top().y+x+y);
				}
				cout<<ans<<"\n";
			}
	}
}