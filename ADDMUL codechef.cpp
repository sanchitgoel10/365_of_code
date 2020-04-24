#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxs = 1e6+5;
ll mod = 1e9+7;
ll oo = 1e15;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second


ll n;
ll st[4*maxs];
ll lazy1[4*maxs];
ll lazy2[4*maxs];
ll lazy3[4*maxs];
ll a[maxs];

ll mul(ll a,ll b)
{
    return (a*b)%mod;
}

ll add(ll a,ll b)
{
    return (a+b)%mod;
}

ll fast(ll x,ll y)
{
    ll res = 1;
    while(y)
    {
        if( y&1 )
            res = mul(res,x);
        y >>= 1;
        x = mul(x,x);
    }
    return res;
}

ll getMid(ll s,ll e)
{
    return s + (e-s)/2;
}

void build(ll ss,ll se,ll si)
{
    if(ss==se)
    {
        st[si] = a[ss];
        return;
    }
    ll mid = getMid(ss,se);
    build(ss,mid,2*si+1);
    build(mid+1,se,2*si+2);
    st[si] = add( st[2*si+1] , st[2*si+2] );
}

void push(ll ss,ll se,ll si)
{
    if( lazy3[si] > 0 )
    {
        st[si] = mul( se-ss+1 ,lazy3[si] );
        if(ss!=se)
        {
            lazy3[2*si+1] = lazy3[si];
            lazy3[2*si+2] = lazy3[si];
            
            lazy2[2*si+1] = 1;
            lazy2[2*si+2] = 1;
            
            lazy1[2*si+1] = 0;
            lazy1[2*si+2] = 0;
        }
        lazy3[si] = 0;
    }
    
    if( lazy2[si] > 1 )
    {
        st[si] = mul( st[si] ,lazy2[si] );
        if(ss!=se)
        {
            lazy2[2*si+1] = mul(lazy2[2*si+1],lazy2[si]);
            lazy2[2*si+2] = mul(lazy2[2*si+2],lazy2[si]);
            
            lazy1[2*si+1] = mul( lazy1[2*si+1] , lazy2[si] );
            lazy1[2*si+2] = mul( lazy1[2*si+2] , lazy2[si] );
        }
        lazy2[si]=1;
    }

    
    if( lazy1[si] )
    {
        st[si] = add( st[si] , mul(se-ss+1,lazy1[si]) );
        if(ss!=se)
        {
            lazy1[2*si+1] = add( lazy1[2*si+1] , lazy1[si] );
            lazy1[2*si+2] = add( lazy1[2*si+2] , lazy1[si] );
        }
        lazy1[si] = 0;
    }
        
}

void update1(ll ss,ll se,ll si,ll qs,ll qe,ll val)
{
    push(ss,se,si);
    if(ss>qe or se < qs)
        return;
    if(ss>=qs and se<=qe)
    {
        st[si] = add( st[si] ,  mul(se-ss+1,val) );
        if(ss!=se)
        {
            lazy1[2*si+1] = add(lazy1[2*si+1] , val);
            lazy1[2*si+2] = add(lazy1[2*si+2] , val);
        }
        return;
    }
    ll mid = getMid(ss,se);
    update1(ss,mid,2*si+1,qs,qe,val);
    update1(mid+1,se,2*si+2,qs,qe,val);
    st[si] = add( st[2*si+1],st[2*si+2] );
}

void update2(ll ss,ll se,ll si,ll qs,ll qe,ll val)
{
    push(ss,se,si);
    if(ss>qe or se < qs)
        return;
    if(ss>=qs and se<=qe)
    {
        st[si] = mul( st[si] ,val );
        if(ss!=se)
        {
            lazy2[2*si+1] = mul(lazy2[2*si+1],val);
            lazy2[2*si+2] = mul(lazy2[2*si+2],val);
            lazy1[2*si+1] = mul(lazy1[2*si+1],val);
            lazy1[2*si+2] = mul(lazy1[2*si+2],val);
        }
        return;
    }
    ll mid = getMid(ss,se);
    update2(ss,mid,2*si+1,qs,qe,val);
    update2(mid+1,se,2*si+2,qs,qe,val);
    st[si] = add( st[2*si+1] , st[2*si+2] );
}

void update3(ll ss,ll se,ll si,ll qs,ll qe,ll val)
{
    push(ss,se,si);
    if(ss>qe or se < qs)
        return;
    if(ss>=qs and se<=qe)
    {
        st[si] = mul( se-ss+1 ,val );
        if(ss!=se)
        {
            lazy3[2*si+1] = val;
            lazy3[2*si+2] = val;
            
            lazy2[2*si+1] = 1;
            lazy2[2*si+2] = 1;
            
            lazy1[2*si+1] = 0;
            lazy1[2*si+2] = 0;
        }
        return;
    }
    ll mid = getMid(ss,se);
    update3(ss,mid,2*si+1,qs,qe,val);
    update3(mid+1,se,2*si+2,qs,qe,val);
    st[si] = add( st[2*si+1] , st[2*si+2] );
}

ll get(ll ss,ll se,ll si,ll qs,ll qe)
{
    
    if( ss>qe or se<qs )
        return 0;
    push(ss,se,si);
    if( ss>=qs and se<=qe )
        return st[si];
    ll mid = getMid(ss,se);
    return add(get(ss,mid,2*si+1,qs,qe) , get(mid+1,se,2*si+2,qs,qe) );
}


int main()
{
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll q;
        cin>>n>>q;
        for(ll i=0;i<n;i++) 
            cin>>a[i];
        build(0,n-1,0);   
        
        while(q--)
        {
            ll type;
            cin>>type;
            if(type==1)
            {
                ll l,r,v;
                cin>>l>>r>>v;
                l--;r--;
                update1(0,n-1,0,l,r,v);
            }
            else if(type==2)
            {
                ll l,r,v;
                cin>>l>>r>>v;
                l--;r--;
                update2(0,n-1,0,l,r,v);
            }
            else if(type==3)
            {
                ll l,r,v;
                cin>>l>>r>>v;
                l--;r--;
                update3(0,n-1,0,l,r,v);
            }
            else
            {
                ll l,r;
                cin>>l>>r;
                l--;r--;
                ll ans = get(0,n-1,0,l,r);
                std::cout << ans << std::endl;
            }
        }
    }
    return 0;
}