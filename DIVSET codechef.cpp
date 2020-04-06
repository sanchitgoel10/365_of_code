#include <bits/stdc++.h>
using namespace std;
long long n,k,c;
long long a[300001];
bool check(long long m)
{
    vector<long long> v[m];
    long long m_i=0;
    for(long long i=0;i<n;i++)
    {
        if(v[m_i].size()==k)break;
        if(v[m_i].size()==0 || v[m_i].back()*c <= a[i])
        {
            v[m_i].push_back(a[i]);
            m_i = (m_i + 1)%m;
        }
    }
    if(v[m-1].size()==k)return true;
    else return false;
}


int main() {
	long long t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k>>c;
	    for(long long i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
			sort(a,a+n);
	    long long l=0;
	    long long h=n+1;
	    while(l<h-1)
	    {

	        long long m = (l+h)/2;
	        if(check(m))l=m;
	        else h=m;
					// cout<<h<<endl;
	    }
	    cout<<l<<endl;
	}
	return 0;
}
