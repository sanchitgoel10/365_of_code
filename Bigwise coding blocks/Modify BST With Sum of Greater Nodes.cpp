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

void printpre(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}

void Modify(node*root,int&sum){
    if(root==NULL)return;
    Modify(root->right,sum);
    sum+=root->data;
    root->data=sum;
    Modify(root->left,sum);
}

int32_t main(){
	FastRead;
	node*root=createbypreorder();
    int sum=0;
    Modify(root,sum);
    printpre(root);
	return 0;
}

