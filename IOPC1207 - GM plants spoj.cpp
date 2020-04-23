/*
The exposure to three dimensions is then (rx*ry*rz), while the exposure to one dimension is (rx*gy*gz) + (ry*gx*gz) + (rz*gx*gy). Adding them, we get:
total reds = (rx*ry*rz) + (rx*gy*gz) + (ry*gx*gz) + (rz*gx*gy)
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

class node{
    public:
    int zero;            //zero=green
    int one;             //one=red
};

node query(node*tree,int*lazy,int s,int e,int l,int r,int tn){
    int diff=e-s+1;
    if(s>e){
        node ans;
        ans.zero=0;
        ans.one=0;
        return ans;
    }
    if(lazy[tn]){
        tree[tn].zero=diff-tree[tn].zero;
        tree[tn].one=diff-tree[tn].one;
        if(s!=e){
            lazy[2*tn]^=1;
            lazy[2*tn+1]^=1;
        }
        lazy[tn]=0;
    }
    if(l>e||r<s){
        node ans;
        ans.zero=0;
        ans.one=0;
        return ans;
    }
    if(s>=l&&e<=r){
        return tree[tn];
    }
    int mid=(s+e)/2;
    node left=query(tree,lazy,s,mid,l,r,2*tn);
    node right=query(tree,lazy,mid+1,e,l,r,2*tn+1);
    
    node ans;
    ans.zero=left.zero+right.zero;
    ans.one=left.one+right.one;
    
    return ans;
}

void update(node*tree,int*lazy,int s,int e,int l,int r,int tn){
    int diff=e-s+1;                     //total lights in range
    if(s>e)return; 
    if(lazy[tn]){                          //lazy pe one store karna is ki operation hoga
        tree[tn].zero=diff-tree[tn].zero;   //off ko on on ko off
        tree[tn].one=diff-tree[tn].one;
        if(s!=e){
            lazy[2*tn]^=1;               //xor isliye kara ki jo bhi smj pehele se ek operation hai agr ek aur aaya to null ho jaye
            lazy[2*tn+1]^=1;
        }
        lazy[tn]=0;
    }
    if(l>e||r<s){
        return;
    }
    if(s>=l&&e<=r){
        tree[tn].zero=diff-tree[tn].zero;
        tree[tn].one=diff-tree[tn].one;
        if(s!=e){
            lazy[2*tn]^=1;
            lazy[2*tn+1]^=1;
        }
        return;
    }
    int mid=(s+e)/2;
    update(tree,lazy,s,mid,l,r,2*tn);
    update(tree,lazy,mid+1,e,l,r,2*tn+1);
    
    tree[tn].zero=tree[2*tn].zero+tree[2*tn+1].zero;
    tree[tn].one=tree[2*tn].one+tree[2*tn+1].one;
}

void build(node*tree,int s,int e,int tn){
    if(s==e){
        tree[tn].zero=1;
        tree[tn].one=0;
        return;
    }
    int mid=(s+e)/2;
    build(tree,s,mid,2*tn);
    build(tree,mid+1,e,2*tn+1);
    
    tree[tn].zero=tree[2*tn].zero+tree[2*tn+1].zero;
    tree[tn].one=tree[2*tn].one+tree[2*tn+1].one;
}

int32_t main(){
	FastRead;
	int t;
	cin>>t;
	int n1,n2,n3,l,r,q,type;
	int ans,r1,g1,r2,g2,r3,g3;
	int x1,y1,z1,x2,y2,z2;
	while(t--){
	    cin>>n1>>n2>>n3;
	    node*tree1 = new node[4*n1];
	    int*lazy1 = new int[4*n1];
	    node*tree2 = new node[4*n2];
	    int*lazy2 = new int[4*n2];
	    node*tree3 = new node[4*n3];
	    int*lazy3 = new int[4*n3];
	    build(tree1,0,n1-1,1);
	    build(tree2,0,n2-1,1);
	    build(tree3,0,n3-1,1);
	    cin>>q;
	    while(q--){
	        cin>>type;
	        if(type==0){
	            cin>>l>>r;
	            update(tree1,lazy1,0,n1-1,l,r,1);
	        }
	        if(type==1){
	            cin>>l>>r;
	            update(tree2,lazy2,0,n2-1,l,r,1);
	        }
	        if(type==2){
	            cin>>l>>r;
	            update(tree3,lazy3,0,n3-1,l,r,1);
	        }
	        
	        if(type==3){
	            cin>>x1>>y1>>z1>>x2>>y2>>z2;
	            r1=query(tree1,lazy1,0,n1-1,x1,x2,1).one;
	            g1=query(tree1,lazy1,0,n1-1,x1,x2,1).zero;
	            
	            r2=query(tree2,lazy2,0,n2-1,y1,y2,1).one;
	            g2=query(tree2,lazy2,0,n2-1,y1,y2,1).zero;
	            
	            r3=query(tree3,lazy3,0,n3-1,z1,z2,1).one;
	            g3=query(tree3,lazy3,0,n3-1,z1,z2,1).zero;
	            
	            ans=r1*r2*r3+r1*g2*g3+r2*g1*g3+r3*g1*g2;
	            cout<<ans<<endl;
	        }
	        
	    }
	}
	
	return 0;
}

