/*
Let us assume that we have a data structure which can give us the next number divisible by p in the range [l r] in O(t) time, t is what we will find out later.

Can you give an estimate of total amortised cost on the total time complexity using the above data structure ?

If we forget that there is any query of type 2, then what will be the total amortised cost ?
As each number is less than 109, in the worst case a number can be divided by p by at most 30 times (when p is 2 and number is 109).
So total time complexity would be O(t) * 30 * N

Now Let us add queries of type 2.
Each number which is replaced will require at most 30 steps to reach 1. So at most M numbers are added.
So total time complexity is O(t) * 30 * (M + N) + Time required to change the data structure for query 2.

Now, if t = O(log N), then we are done.

*/

#include<iostream>
#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include<algorithm>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define all(c) c.begin(), c.end() 
#define fr(type,i,n) for(type i=0;i<n;i++)
#define sz(a) int((a).size()) 
#define ll long long int
#define ull unsigned long long
#define tr(c,it) for(typeof((c).begin()) (it) = (c).begin();(it)!=(c).end();(it)++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pi 3.1415926535897932384626433832795
#define endl "\n"
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	vector<ull> vec;
	set<int> myset[6];
	ull temp;
	
	fr(int,i,n)
	{
			cin>>temp;
			vec.pb(temp);
			if(temp%2 == 0)
				myset[2].insert(i);
			if(temp%3 == 0)
				myset[3].insert(i);
			if(temp%5 == 0)
				myset[5].insert(i);
	}
	
	int m;
	cin>>m;
	while(m--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int l,r,p;
			cin>>l>>r>>p;
			set<int>::iterator a= lower_bound(myset[p].begin(), myset[p].end(), l-1);
			
			vi del;
			
			for(set<int>::iterator it = a;it!=myset[p].end();it++)
			{
					if(*it>r-1)
						break; //since sorted
						
					vec[*it]/=p;
					if(vec[*it]%p)
						del.pb(*it);
			}
			
			for(vi::iterator it=del.begin();it!=del.end();it++)
				myset[p].erase(*it);
		}
		else
		{
			int l,d;
			cin>>l>>d;
			
			if(vec[l-1] % 2==0)
				myset[2].erase(l-1);
				
			if(vec[l-1] % 3==0)
				myset[3].erase(l-1);
				
			if(vec[l-1] % 5==0)
				myset[5].erase(l-1);
				
			if(d%2==0)
				myset[2].insert(l-1);
			
			if(d%3==0)
				myset[3].insert(l-1);
				
			if(d%5==0)
				myset[5].insert(l-1);
				
			vec[l-1] = d;
		}
	}
	fr(int,i,n)
		cout<<vec[i]<<" ";
	cout<<"\n";
	return 0;
}
