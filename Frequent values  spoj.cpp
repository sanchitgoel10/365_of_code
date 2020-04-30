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
    int pv,pc;        //pv=prefix value,pc=prefix count
    int sv,sc;        //sv=suffix value
    int ans;           //ans max length
};

node query(node*tree,int s,int e,int L,int R,int tn){
    if(L>e||R<s){
        node a;
        a.pv=INT_MIN;
        a.pc=INT_MIN;
        a.sv=INT_MIN;
        a.sc=INT_MIN;
        a.ans=INT_MIN;
        return a;
    }
    if(s>=L&&e<=R){
        return tree[tn];
    }
    int mid=(s+e)/2;
    node l=query(tree,s,mid,L,R,2*tn);
    node r=query(tree,mid+1,e,L,R,2*tn+1);
    
    node a;
    a.pv=l.pv;
    a.sv=r.sv;
    a.pc=l.pc;
    a.sc=r.sc;
    if(l.pv==r.pv){
        a.pc+=r.pc;
    }
    if(r.sv==l.sv){
        a.sc+=l.sc;
    }
    a.ans=max(l.ans,r.ans);
    if(l.sv==r.pv){
        a.ans=max(a.ans,l.sc+r.pc);
    }
    return a;
}

void build(node*tree,int*arr,int s,int e,int tn){
    if(s==e){
        tree[tn].pv=arr[s];
        tree[tn].sv=arr[s];
        tree[tn].ans=1;
        tree[tn].pc=1;
        tree[tn].sc=1;
        return;
    }
    int mid=(s+e)/2;
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    node l=tree[2*tn];
    node r=tree[2*tn+1];
    
    tree[tn].pv=l.pv;
    tree[tn].sv=r.sv;
    tree[tn].pc=l.pc;
    tree[tn].sc=r.sc;
    if(l.pv==r.pv){
        tree[tn].pc+=r.pc;
    }
    if(r.sv==l.sv){
        tree[tn].sc+=l.sc;
    }
    tree[tn].ans=max(l.ans,r.ans);
    if(l.sv==r.pv){
        tree[tn].ans=max(tree[tn].ans,l.sc+r.pc);
    }
    
}

int32_t main(){
	FastRead;
	int n,q;
	while(1){
	    cin>>n;
	    if(!n)break;
	    cin>>q;
	    int*arr = new int[n];
	    For(i,0,n)cin>>arr[i];
	    node*tree = new node[4*n];
	    build(tree,arr,0,n-1,1);
	    int l,r;
	    while(q--){
	        cin>>l>>r;
	        l--;r--;
	        cout<<query(tree,0,n-1,l,r,1).ans<<endl;
	    }
	}
	return 0;
}

