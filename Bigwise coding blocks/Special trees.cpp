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
    node(int d){
        data=d;
        left=right=NULL;
    }
};

void printinorder(node*root){
    if(root==NULL)return ;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

node* createspecial(int*arr,int s,int e){
    if(s>e)return NULL;
    int mi=s;
    for(int i=s+1;i<=e;i++){
        if(arr[i]>arr[mi]){
            mi=i;
        }
    }
    node *root= new node(arr[mi]);
    root->left=createspecial(arr,s,mi-1);
    root->right=createspecial(arr,mi+1,e);
    return root;
}

int32_t main(){
	FastRead;
	int n;
    cin>>n;
    int*arr = new int[n];
    For(i,0,n)cin>>arr[i];
    
    node*root=createspecial(arr,0,n-1);
    printinorder(root);
	return 0;
}

