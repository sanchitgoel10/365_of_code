#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
bool ss(ll x,ll y)
{
    return abs(x)<abs(y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t,i,k,neg,zero,prod,i1,i2,j1,j2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll a[n];
        neg=0;
        zero=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n,ss);
         for(i=n-k;i<n;i++) // Last K elements with maximum absolute value
        {
            if(a[i]<0)
            neg++;
            else
            if(a[i]==0)
            zero++;
        }
        if(neg%2==0 || zero>=1)// Positive hi hoga hamesha 
        {
            prod=1;
            //cout<<"a"<<endl;
            for(i=n-k;i<n;i++)
            {
                if(a[i]<0)
                prod=((prod%mod)*(a[i]+mod))%mod;
                else
                prod=((prod%mod)*(a[i]%mod))%mod;
            }
            cout<<prod<<endl;
        }
        else
        {
            i1=n;
            j1=n;
            for(i=n-k;i<n;i++)
            {
                if(a[i]>0 && i1==n)
                i1=i;
                if(a[i]<0 && j1==n)
                j1=i;
            }
            i2=-1;
            j2=-1;
            for(i=n-k-1;i>=0;i--)
            {
                if(a[i]<0 && i2==-1)
                i2=i;
                if(a[i]>0 && j2==-1)
                j2=i;
            }
            //cout<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<endl;
            if((i1==n || i2==-1) && (j1==n || j2==-1))
            {
                prod=1;
                //All the elements are negative
                for(i=0;i<k;i++)
                {
                    if(a[i]<0)
                    prod=((prod%mod)*(a[i]+mod))%mod;
                    else
                    prod=((prod%mod)*(a[i]%mod))%mod;
                }
                cout<<prod<<endl;
            }
            else // Only one possibilty
            if(i1==n || i2==-1)
            {
                prod=1;
                //cout<<"c"<<endl;
                for(i=n-k;i<n;i++)
                {
                    if(i==j1)
                    prod=((prod%mod)*(a[j2]+mod))%mod;
                    else
                    prod=((prod%mod)*(a[i]+mod))%mod;
                }
                cout<<prod<<endl;
            }
            else// ONly 1 possibilty
            if(j1==n || j2==-1)
            {
                prod=1;
                //cout<<"d"<<endl;
                for(i=n-k;i<n;i++)
                {
                    if(i==i1)
                    prod=((prod%mod)*(a[i2]+mod))%mod;
                    else
                    prod=((prod%mod)*(a[i]+mod))%mod;
                }
                cout<<prod<<endl;
            }
            else//Both possibilty exist i.e we can replace a positive number with neagtive or vice versa
            if(a[i1]*a[j2]<a[i2]*a[j1])
            {
                prod=1;
                //cout<<"e"<<endl;
                for(i=n-k;i<n;i++)
                {
                    if(i==i1)
                    prod=((prod%mod)*(a[i2]+mod))%mod;
                    else
                    prod=((prod%mod)*(a[i]+mod))%mod;
                }
                cout<<prod<<endl;
            }
            else
            {
                prod=1;
                //cout<<"f"<<endl;
                for(i=n-k;i<n;i++)
                {
                    if(i==j1)
                    prod=((prod%mod)*(a[j2]+mod))%mod;
                    else
                    prod=((prod%mod)*(a[i]+mod))%mod;
                }
                cout<<prod<<endl;
            }
        }
    }
    return 0;
}