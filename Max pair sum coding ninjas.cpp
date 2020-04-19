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

class node{
    public:
    int sum;
    int m;
};

node query(node*tree,int s,int e,int l,int r,int tn){
    if(r<s||l>e){
        node ans;
        ans.sum=0;
        ans.m=0;
        return ans;
    }
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid=(s+e)/2;
    
    node left=query(tree,s,mid,l,r,2*tn);
    node right=query(tree,mid+1,e,l,r,2*tn+1);
    
    node ans;
    
 	ans.sum=max(left.m+right.m,max(left.sum,right.sum));
    ans.m=max(left.m,right.m);
    return ans;
}

void update(node*tree,int*arr,int s,int e,int tn,int i,int v){
    if(s==e){
        arr[i]=v;
        tree[tn].m=v;
        return;
    }
    int mid=(s+e)/2;
    if(i>mid){
        update(tree,arr,mid+1,e,2*tn+1,i,v);
    }else{
        update(tree,arr,s,mid,2*tn,i,v);
    }
    
    tree[tn].sum=max(tree[2*tn].m+tree[2*tn+1].m,max(tree[2*tn].sum,tree[2*tn+1].sum));
    tree[tn].m=max(tree[2*tn].m,tree[2*tn+1].m);
    
}

void build(node*tree,int*arr,int s,int e,int tn){
    if(s==e){
        tree[tn].sum=0;
        tree[tn].m=arr[s];
        return;
    }
    int mid=(s+e)/2;
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    tree[tn].sum=max(tree[2*tn].m+tree[2*tn+1].m,max(tree[2*tn].sum,tree[2*tn+1].sum));
    tree[tn].m=max(tree[2*tn].m,tree[2*tn+1].m);
}

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    int *arr = new int[n];
    For(i,0,n)cin>>arr[i];
    node *tree = new node[4*n];
    build(tree,arr,0,n-1,1);
    int q;
    cin>>q;
    char type;
    int x,y;
    while(q--){
        cin>>type>>x>>y;
        if(type=='Q'){
            x--;y--;
            cout<<query(tree,0,n-1,x,y,1).sum<<endl;
        }else{
            x--;
            update(tree,arr,0,n-1,1,x,y);
        }
    }
	return 0;
}

