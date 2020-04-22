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

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int query(int*tree,int*lazy,int s,int e,int l,int r,int tn){
    if(s>e)return 0;
    if(lazy[tn]!=0){
        tree[tn]+=lazy[tn]*(e-s+1);
        if(s!=e){
            lazy[2*tn]+=lazy[tn];
            lazy[2*tn+1]+=lazy[tn];
        }
        lazy[tn]=0;
    }
    if(l>e||s>r){
        return 0;
    }
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid=(s+e)/2;
    int ans1=query(tree,lazy,s,mid,l,r,2*tn);
    int ans2=query(tree,lazy,mid+1,e,l,r,2*tn+1);
    
    return ans1+ans2;
}

void update(int*tree,int *lazy,int s,int e,int l,int r,int tn,int v){
    if(s>e)return;
    if(lazy[tn]!=0){
        tree[tn]+=lazy[tn]*(e-s+1);
        if(s!=e){
            lazy[2*tn]+=lazy[tn];
            lazy[2*tn+1]+=lazy[tn];
        }
        lazy[tn]=0;
    }
    if(l>e||s>r){
        return;
    }
    if(s>=l&&e<=r){
        tree[tn]+=v*(e-s+1);
        if(s!=e){
            lazy[2*tn]+=v;
            lazy[2*tn+1]+=v;
        }
        return;
    }
    int mid=(s+e)/2;
    update(tree,lazy,s,mid,l,r,2*tn,v);
    update(tree,lazy,mid+1,e,l,r,2*tn+1,v);
    
    tree[tn]=tree[2*tn]+tree[2*tn+1];
}

int32_t main(){
	FastRead;
	int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        int* tree = new int[4*n]();
        int* lazy = new int[4*n]();
        int l,r,v;
        int type;
        while(c--){
            cin>>type;
            if(type){
            	cin>>l>>r;
            	l--;r--;
                cout<<query(tree,lazy,0,n-1,l,r,1)<<endl;
            }else{
            	cin>>l>>r>>v;
                l--;r--;
                update(tree,lazy,0,n-1,l,r,1,v);
            }
        }
    }
	return 0;
}

