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
#define w(t) int t;cin>>t;while(t--)

int sieve[1000005];

class node{
    public:
    int ans;
    int count;    //number of entries for a[i]>1
};

void pre(){
    int vis[1000005];
    For(i,0,1000005){
        sieve[i]=1;
        vis[i]=0;
    }
    
    sieve[0]=1;
    sieve[1]=1;
    vis[0]=1;
    vis[1]=1;
    For(i,2,1000005){
        if(sieve[i]==1){
            for(int j=i;j<1000005;j+=i){
                if(vis[j]==0){
                    sieve[j]=i;
                    vis[j]=1;
                }
            }
        }
    }
}

int query(node*tree,int s,int e,int l,int r,int tn){
    if(l>e||r<s){
        return -1;
    }
    if(s>=l&&e<=r){
        return tree[tn].ans;
    }
    int mid=(s+e)/2;
    int ans1=query(tree,s,mid,l,r,2*tn);
    int ans2=query(tree,mid+1,e,l,r,2*tn+1);
    
    return max(ans1,ans2);
}

void update(node*tree,int*arr,int s,int e,int l,int r,int tn){
    if(l>e||r<s){
        return;
    }
    if(tree[tn].count==0){                 //agar saare number one ho gaye hai to update ka point nhi
        return;
    }
    if(s==e){
        arr[s]/=sieve[arr[s]];
        tree[tn].ans=sieve[arr[s]];
        if(arr[s]>1){
            tree[tn].count=1;
        }else{
            tree[tn].count=0;
        }
        return;
    }
    int mid=(s+e)/2;
    update(tree,arr,s,mid,l,r,2*tn);
    update(tree,arr,mid+1,e,l,r,2*tn+1);
    
    tree[tn].ans=max(tree[2*tn].ans,tree[2*tn+1].ans);
    tree[tn].count=tree[2*tn].count+tree[2*tn+1].count;
}

void build(node*tree,int*arr,int s,int e,int tn){
    if(s==e){
        tree[tn].ans=sieve[arr[s]];
        if(arr[s]>1){
            tree[tn].count=1;
        }else{
            tree[tn].count=0;
        }
        return;
    }
    
    int mid=(s+e)/2;
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    tree[tn].ans=max(tree[2*tn].ans,tree[2*tn+1].ans);
    tree[tn].count=tree[2*tn].count+tree[2*tn+1].count;
}

int32_t main(){
	FastRead;
	pre();
	int n,m;
	int type,l,r;
	w(t){
	    cin>>n>>m;
	    int*arr = new int[n];
	    For(i,0,n)cin>>arr[i];
	    node*tree = new node[4*n];
	    build(tree,arr,0,n-1,1);
	   // For(i,0,14){
	   //     cout<<tree[i].ans<<" "<<tree[i].count<<endl;
	   // }
	    while(m--){
	        cin>>type;
	        if(type==0){
	            cin>>l>>r;
	            l--;r--;
	            update(tree,arr,0,n-1,l,r,1);
	        }else{
	            cin>>l>>r;
	            l--;r--;
	            cout<<query(tree,0,n-1,l,r,1)<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}

