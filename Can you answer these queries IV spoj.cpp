/*This code works for this input not eof types
5
1 2 3 4 5
5
1 2 4
0 2 4
1 2 4
0 4 5
1 1 5
4
10 10 10 10
3
1 1 4
0 2 3
1 1 4
0                //0 dena hoga last me

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
#define mod 1000000007
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)


int query(int *tree,int s,int e,int l,int r,int tn){
    if(l>e||r<s)return 0;
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid =(s+e)/2;
    int ans1=query(tree,s,mid,l,r,2*tn);
    int ans2=query(tree,mid+1,e,l,r,2*tn+1);
    
    return ans1+ans2;
}

void update(int*tree,int s,int e,int l,int r,int tn){
    int segsum=(e-s+1);
    if(tree[tn]==segsum)return;     //agar saare 1 ho gaye to fayda kya update karane ka
    
    if(l>e||r<s)return;
    if(s==e){
        tree[tn]=sqrt(tree[tn]);
        return;
    }
    int mid=(s+e)/2;
    update(tree,s,mid,l,r,2*tn);
    update(tree,mid+1,e,l,r,2*tn+1);
    
    tree[tn]=tree[2*tn]+tree[2*tn+1];
}

void build(int*tree,int*arr,int s,int e,int tn){
    if(s==e){
        tree[tn]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    tree[tn]=(tree[2*tn]+tree[2*tn+1]);
}

int32_t main(){
	FastRead;
	int n;
	int q;
	int type,x,y;
	int tc=1;
	while(1){
	    cin>>n;
	    if(n==0)break;
	    cout<<"Case #"<<tc<<":"<<endl;
	    int *arr = new int[n];
	    int *tree = new int[4*n]; 
	    For(i,0,n)cin>>arr[i];
	    build(tree,arr,0,n-1,1);
	    cin>>q;
	    while(q--){
	        cin>>type;
	        if(type){
	            cin>>x>>y;
	            x=min(x,y);
	            y=max(x,y);
	            x--;y--;
	            cout<<query(tree,0,n-1,x,y,1)<<endl;
	        }else{
	            cin>>x>>y;
	            x=min(x,y);
	            y=max(x,y);
	            x--;y--;
	            update(tree,0,n-1,x,y,1);
	        }
	    }
	    tc++;
	}
	return 0;
}

