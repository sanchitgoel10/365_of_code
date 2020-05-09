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

char a[1000];
vec v;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d):data(d),left(NULL),right(NULL){
    }
};

void StringtoInt(){
    char *ans = strtok(a," ");
    while(ans!=NULL){
        v.pb(stoi(ans));
        ans=strtok(NULL," ");
    }
}

node* CreateTree(){
    if(v.size()==0)return NULL;

    int num=v[0];
    node*root=new node(num);
    queue<node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<v.size()){
        node*temp=q.front();
        q.pop();

        num=v[i++];
        temp->left=new node(num);
        q.push(temp->left);
        if(i>=v.size())break;

        num=v[i++];
        temp->right=new node(num);
        q.push(temp->right);
        if(i>=v.size())break;
    }

    return root;
}

int Sum(node*root){
    if(root==NULL)return 0;

    int l=Sum(root->left);
    int r=Sum(root->right);

    return root->data+l+r;
}

int CountSubTrees(node*root,int x){
    if(root==NULL)return 0;

    int ans=0;
    if(Sum(root)==x)ans++;

    int l=CountSubTrees(root->left,x);
    int r=CountSubTrees(root->right,x);

    return ans+l+r;
}

int32_t main(){
	FastRead;
	w(t){
        v.clear();
        cin.ignore();
        cin.getline(a,1000);
        StringtoInt();
        int x;
        cin>>x;
        node*root=CreateTree();
        cout<<CountSubTrees(root,x)<<endl;
    }
	return 0;
}

