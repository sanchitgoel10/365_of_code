#include<bits/stdc++.h>
using namespace std;

struct node{
    long long ssum;
    long long sum;
    int lazyset;
    int setval;
    int addval;
    
    void combine(node &a,node&b){
        ssum=a.ssum+b.ssum;
        sum=a.sum+b.sum;
    }
};
void buildtree(int*arr,node* tree,int st,int end,int tn)
{
    
	tree[tn].addval=0;
	tree[tn].lazyset=0;
    if(st>end)
    {
        return;
    }
    if(st==end){
        tree[tn].ssum=arr[st]*arr[st];
        tree[tn].sum=arr[st];
        return;
    }
    int mid=(st+end)/2;
    buildtree(arr,tree,st,mid,2*tn);
    buildtree(arr,tree,mid+1,end,2*tn+1);
    node l=tree[tn*2];
    node r=tree[tn*2+1];
    
    tree[tn].combine(l,r);
    
}

void pushdown(node*tree,int st,int end,int tn)
{
    int mid=(st+end)/2;
    if(tree[tn].lazyset==1)
    {
        tree[tn].lazyset=0;
        tree[2*tn].lazyset=1;
        tree[2*tn+1].lazyset=1;
        
        tree[2*tn].setval=tree[tn].setval;
        tree[2*tn+1].setval=tree[tn].setval;
        
        tree[2*tn].addval=0;
        tree[2*tn+1].addval=0;
        
        tree[tn*2].sum=(mid-st+1)*tree[tn].setval;
        tree[tn*2+1].sum=(end-mid)*tree[tn].setval;
        
        tree[2*tn].ssum=(mid-st+1)*tree[tn].setval*tree[tn].setval;
        tree[2*tn+1].ssum=(end-mid)*tree[tn].setval*tree[tn].setval;
        
    }
    if(tree[tn].addval)
    {
        
        tree[tn*2].addval+=tree[tn].addval;
        tree[tn*2+1].addval+=tree[tn].addval;
        
        tree[tn*2].ssum+=2*tree[tn].addval*tree[2*tn].sum+tree[tn].addval*tree[tn].addval*(mid-st+1);
        tree[tn*2+1].ssum+=2*tree[tn].addval*tree[2*tn+1].sum+tree[tn].addval*tree[tn].addval*(end-st);
        
        tree[2*tn].sum+=tree[tn].addval*(mid-st+1);
        tree[2*tn+1].sum+=tree[tn].addval*(end-st);
        
        tree[tn].addval=0;
    }
}

long long query(node*tree,int st,int end,int tn,int str,int endr)
{
    
    if(st>endr||end<str||st>end)
    {
        if(tree[tn].lazyset||tree[tn].addval)
        {
            pushdown(tree,st,end,tn);
        }
        return 0;
    }
    if(tree[tn].lazyset||tree[tn].addval)
    {
         pushdown(tree,st,end,tn);
    }
    if(st>=str&&end<=endr)
    {
        return tree[tn].ssum;
    }
    int mid=(st+end)/2;
    
    return query(tree,st,mid,2*tn,str,endr)+query(tree,mid+1,end,2*tn+1,str,endr);
    
}

void updateadd(node*tree,int st,int end,int tn,int str,int endr,int value)
{
     if(st>endr||end<str||st>end)
         return ;
    if(st>=str&&end<=endr)
    {
        tree[tn].addval+=value;
        tree[tn].ssum+=(long long)(end-st+1)*value*value+(long long)2*value*(tree[tn].sum);
        tree[tn].sum+=(long long)(end-st+1)*value;
        return;
    }
    int mid=(st+end)/2;
    if(tree[tn].lazyset||tree[tn].addval)
    {
         pushdown(tree,st,end,tn);
    }
    updateadd(tree,st,mid,2*tn,str,endr,value);
    updateadd(tree,mid+1,end,2*tn+1,str,endr,value);
    
    node l=tree[tn*2];
    node r=tree[tn*2+1];
    
    tree[tn].combine(l,r);
}
void updateset(node*tree,int st,int end,int tn,int str,int endr,int value)
{
    if(st>endr||end<str||st>end)
         return ;
    if(st>=str&&end<=endr)
    {
        tree[tn].lazyset=1;
        tree[tn].setval=value;
        tree[tn].ssum=(long long)(end-st+1)*value*value;
        tree[tn].sum=(long long)(end-st+1)*value;
        tree[tn].addval=0;
        return;
    }
    int mid=(st+end)/2;
    if(tree[tn].lazyset||tree[tn].addval)
    {
         pushdown(tree,st,end,tn);
    }
    updateset(tree,st,mid,2*tn,str,endr,value);
    updateset(tree,mid+1,end,2*tn+1,str,endr,value);
    
    node l=tree[tn*2];
    node r=tree[tn*2+1];
    
    tree[tn].combine(l,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
   
    while(t--)
    {
        cout<<"Case"<<" "<<i<<":"<<endl;
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int k=0;k<n;k++)
            cin>>arr[k];
        node tree[4*n];
        buildtree(arr,tree,0,n-1,1);
        while(q--)
        {
            int c,l,r;
            cin>>c>>l>>r;
            if(c==2){
                long long ans=query(tree,0,n-1,1,l-1,r-1);
                cout<<ans<<endl;
            }if(c==0){
                int x;
                cin>>x;
                updateset(tree,0,n-1,1,l-1,r-1,x);
            }if(c==1){
                int x;
                cin>>x;
                updateadd(tree,0,n-1,1,l-1,r-1,x);
            }
        }
        
        i++;
    }
	
}
