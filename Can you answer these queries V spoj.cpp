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


bool comp(int a, int b) 
{ 
    return (a < b); 
}

class node{
    public:
    int sum;
    int msum;
    int bpref;
    int bsuff;
};

node query(node*tree,int s,int e,int l,int r,int tn){
    if(r<s||l>e){
        node ans;
        ans.sum=0;         //sum 0 hoga dhyan rakhio
        ans.msum=INT_MIN;
        ans.bsuff=INT_MIN;
        ans.bpref=INT_MIN;
        return ans;
    }
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid=(s+e)/2;
    
    node left=query(tree,s,mid,l,r,2*tn);
    node right=query(tree,mid+1,e,l,r,2*tn+1);
    
    node ans;
    
    ans.msum=max({left.msum,right.msum,left.sum+right.bpref,left.bsuff+right.sum,left.bsuff+right.bpref},comp);
    ans.sum=left.sum+right.sum;
    ans.bpref=max({left.sum+right.bpref,left.bpref},comp);
    ans.bsuff=max({right.sum+left.bsuff,right.bsuff},comp);
    
    return ans;
}

void build(node*tree ,int*arr,int s,int e,int tn){
    if(s==e){
        tree[tn].sum=arr[s];
        tree[tn].msum=arr[s];      //subarray hai subsequence nhi dhyan rakhi
        tree[tn].bpref=arr[s];
        tree[tn].bsuff=arr[s];
        return;
    }
    int mid=(s+e)/2;
    
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    node left=tree[2*tn];
    node right=tree[2*tn+1];
    
    tree[tn].msum=max({left.msum,right.msum,left.sum+right.bpref,left.bsuff+right.sum,left.bsuff+right.bpref},comp);
    tree[tn].sum=left.sum+right.sum;
    tree[tn].bpref=max({left.sum+right.bpref,left.bpref},comp);
    tree[tn].bsuff=max({right.sum+left.bsuff,right.bsuff},comp);
    
}


int32_t main(){
	FastRead;
	int t,n,q,x1,x2,y1,y2;
	cin>>t;
	while(t--){
	    cin>>n;
	    int*arr = new int[n];
	    For(i,0,n)cin>>arr[i];
	    node*tree = new node[4*n];
	    build(tree,arr,0,n-1,1);
	    cin>>q;
	    while(q--){
	        cin>>x1>>y1>>x2>>y2;
	        x1--;x2--;y1--;y2--;
	        int ans;               //pen paper leke baith 2 case bana smj ayega
	        if(x2>y1){
	            ans=query(tree,0,n-1,y1+1,x2-1,1).sum;
	            ans+=query(tree,0,n-1,x1,y1,1).bsuff;
	            ans+=query(tree,0,n-1,x2,y2,1).bpref;
	        }else{
	            ans=query(tree,0,n-1,x2,y1,1).msum;
	            ans=max({ans,query(tree,0,n-1,x1,x2-1,1).bsuff+query(tree,0,n-1,x2,y2,1).bpref,query(tree,0,n-1,x1,y1,1).bsuff+query(tree,0,n-1,y1+1,y2,1).bpref},comp);
	        }
	        cout<<ans<<endl;
	    }
	}
	return 0;
}

