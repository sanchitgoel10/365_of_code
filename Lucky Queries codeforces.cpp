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
    int n4,n7,n47,n74;       //n4=number of 4 digits 
                             //n47 is no decreasing max length      n74 non increasing max length
};

void update(node*tree,int*lazy,int s,int e,int L,int R,int tn){
    if(lazy[tn]){
        swap(tree[tn].n4,tree[tn].n7);
        swap(tree[tn].n47,tree[tn].n74);
        if(s!=e){
            lazy[2*tn]^=1;
            lazy[2*tn+1]^=1;
        }
        lazy[tn]=0;
    }
    if(L>e||R<s)return;
    if(s>=L&&e<=R){
        swap(tree[tn].n4,tree[tn].n7);
        swap(tree[tn].n47,tree[tn].n74);
        if(s!=e){
            lazy[2*tn]^=1;                     //xor kara hai
            lazy[2*tn+1]^=1;
        }
        return;
    }
    int mid=(s+e)/2;
    update(tree,lazy,s,mid,L,R,2*tn);
    update(tree,lazy,mid+1,e,L,R,2*tn+1);
    
    node l=tree[2*tn];
    node r=tree[2*tn+1];
    
    tree[tn].n4=l.n4+r.n4;
    tree[tn].n7=l.n7+r.n7;
    tree[tn].n47=max(l.n47+r.n7,l.n4+r.n47);
    tree[tn].n74=max(l.n74+r.n4,l.n7+r.n74);
}

void build(node*tree,int*arr,int s,int e,int tn){
    if(s==e){
        if(arr[s]==4){
            tree[tn].n4=1;
            tree[tn].n7=0;
        }else{
            tree[tn].n7=1;
            tree[tn].n4=0;
        }
        tree[tn].n47=1;
        tree[tn].n74=1;
        return;
    }
    int mid=(s+e)/2;
    build(tree,arr,s,mid,2*tn);
    build(tree,arr,mid+1,e,2*tn+1);
    
    node l=tree[2*tn];
    node r=tree[2*tn+1];
    
    tree[tn].n4=l.n4+r.n4;
    tree[tn].n7=l.n7+r.n7;
    tree[tn].n47=max(l.n47+r.n7,l.n4+r.n47);
    tree[tn].n74=max(l.n74+r.n4,l.n7+r.n74);
    
}

int32_t main(){
    FastRead;
    int n,m;
    cin>>n>>m;
    int*arr = new int[n];
    string s;
    cin>>s;
    For(i,0,n){
        arr[i]=s[i]-'0';
    }
    node*tree = new node[4*n];
    int*lazy = new int[4*n]();
    build(tree,arr,0,n-1,1);
    string x;
    int l,r;
    while(m--){
        cin>>x;
        if(x=="count"){
            if(lazy[1]){
               swap(tree[1].n4,tree[1].n7);
              swap(tree[1].n47,tree[1].n74);
              if(0!=n-1){
                  lazy[2*1]^=1;
                  lazy[2*1+1]^=1;
              }
              lazy[1]=0;
              cout<<tree[1].n47<<endl;
            }else{
                cout<<tree[1].n47<<endl;
            }
        }else{
            cin>>l>>r;
            l--,r--;
            update(tree,lazy,0,n-1,l,r,1);
        }
    }
    return 0;
}

