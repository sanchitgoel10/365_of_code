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
#define pi 3.1415926535897932384626433832795
#define inf 1e18
#define ff first
#define ss second
#define For(i,a,b) for(int i=a;i<b;i++)
#define w(t) int t;cin>>t;while(t--)

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move





//Video dekh code ki agar na h0


class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d):data(d),left(NULL),right(NULL){
    }
};

node* createbypreorder(){
    int data;
    cin>>data;
    if(data==-1)return NULL;
    node* root = new node(data);
    root->left=createbypreorder();
    root->right=createbypreorder();
    return root;
}

node* Find(node*root,int x){
    if(root==NULL||root->data==x)return root;
    node*l=Find(root->left,x);
    node*r=Find(root->right,x);
    return (l==NULL?r:l);
}

int count(node*root){
    if(root==NULL)return 0;
    int l=count(root->left);
    int r=count(root->right);
    return 1+l+r;
}

int Bigbang(node*root,int n,int x){
    node*t=Find(root,x);
    int countlefttree=count(t->left);
    int countrighttree=count(t->right);
    int remaining=n-(countlefttree+countrighttree)-1;

    if(countlefttree>countrighttree+remaining)return 1;
    if(countrighttree>countlefttree+remaining)return 1;
    if(remaining>countlefttree+countrighttree)return 1;

    return 0;
}


int32_t main(){
	FastRead;
    int N,n,x;
    cin>>N>>n>>x;
	node*root=createbypreorder();
    cout<<Bigbang(root,n,x);
    
	return 0;
}

