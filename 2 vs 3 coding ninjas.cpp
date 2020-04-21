#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 1000000
int arr[max];
long long tree[4*max];
string str;

ll p[100005];
void fastpow()
{
    p[0]=1;
    for(int i=1;i<=100000;++i)
        p[i]=(p[i-1]*2)%3;
}
void buildtree(int s,int e,int tn)
{
    if(s>e)
        return;
    if(s==e)
    {
        tree[tn]=str[s]-'0';
        return;
    }
    int mid=(s+e)/2;
    buildtree(s,mid,2*tn);
    buildtree(mid+1,e,2*tn+1);
    
     
    ll shift = p[e-mid];
    
    tree[tn]=(tree[2*tn]*shift+tree[2*tn+1])%3;
    
}
void update(int s,int e,int tn,int index)
{
    if(s>e)
        return;
    if(s==e)
    {
        str[index]=1;
        tree[tn]=1;
        return;
    }
    int mid=(s+e)/2;
    
    if(index>mid)
    {
        update(mid+1,e,2*tn+1,index);
    }else{
        update(s,mid,2*tn,index);
    }
    
    ll shift = p[e-mid];
    
    tree[tn]=(tree[2*tn]*shift+tree[2*tn+1])%3;
    
}
ll query(int s,int e,int tn,int l,int r)
{
    if(s>r||e<l)
        return 0;
    if(s>=l&&e<=r)
    {
         
        ll shift=p[r-e];
        
        return (tree[tn]*shift)%3;
    }
    int mid=(s+e)/2;
    ll ans1=query(s,mid,2*tn,l,r);
    ll ans2=query(mid+1,e,2*tn+1,l,r);
    
    return (ans1%3+ans2%3)%3;
}
int main()
{
    fastpow();
    int n;
    cin>>n;
    cin>>str;
    buildtree(0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int c,l;
        cin>>c>>l;
        if(c==0)
        {
            int r;
            cin>>r;
            int ans=query(0,n-1,1,l,r);
            cout<<ans<<endl;
        }
        if(c==1)
        {
            update(0,n-1,1,l);
        }
    }
}