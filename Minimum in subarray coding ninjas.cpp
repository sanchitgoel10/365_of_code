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

int query(int*tree,int s,int e,int l,int r,int tn){
    if(r<s||l>e){
        return INT_MAX;
    }
    if(s>=l&&e<=r){  
        return tree[tn];
    }
    int mid=(s+e)/2;
    
    int ans1=query(tree,s,mid,l,r,2*tn);
    int ans2=query(tree,mid+1,e,l,r,2*tn+1);
    
    return min(ans1,ans2);
}

void update(int*arr,int*tree,int s,int e,int tn,int i,int v){
    if(s==e){
        arr[i]=v;
        tree[tn]=v;
        return ;
    }
    int mid=(s+e)/2;
    
    if(i>mid){
        update(arr,tree,mid+1,e,2*tn+1,i,v);
    }else{
        update(arr,tree,s,mid,2*tn,i,v);
    }
    
    tree[tn]=min(tree[2*tn],tree[2*tn+1]);
}

void buildtree(int*arr,int*tree,int s,int e,int tn){
    if(s==e){
        tree[tn]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    
    buildtree(arr,tree,s,mid,2*tn);
    buildtree(arr,tree,mid+1,e,2*tn+1);
    
    tree[tn]=min(tree[2*tn],tree[2*tn+1]);
}

int32_t main(){
	FastRead;
	int n,q;
    cin>>n>>q;
	int *arr = new int[n];
    For(i,0,n){
        cin>>arr[i];
    }
    int*tree = new int[4*n];
    buildtree(arr,tree,0,n-1,1);
    
    int x,y;
    char type;
    while(q--){
        cin>>type;
        cin>>x>>y;
        if(type =='q'){
            x--;y--;
            cout<<query(tree,0,n-1,x,y,1)<<endl;;
        }else{
            x--;
            update(arr,tree,0,n-1,1,x,y);
        }
    }
	return 0;
}

