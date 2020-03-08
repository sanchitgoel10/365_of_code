#include<bits/stdc++.h>
using namespace std;
map<int,int> mk;
map<int,int> mq;

void addpairk(int n)
{
    int temp=0;
    while(n%2==0)
    {
        temp++;
        n=n/2;
    }
    if(temp>0)
   mk[2]=temp;
    for(int i=3;i*i<=n;i+=2)
    {
        temp=0;
        while(n%i==0)
        {
            temp++;
            n=n/i;
        }
        if(temp>0)
        	mk[i]=temp;
    }
    if(n>2)
        mk[n]=1;
}

void addpairq(int n)
{
    int temp=0;
    while(n%2==0)
    {
        temp++;
        n=n/2;
    }
    if(mk[2]>0)
    mq[2]=temp;
    for(int i=3;i*i<=n;i+=2)
    {
        temp=0;
        while(n%i==0)
        {
            temp++;
            n=n/i;
        }
        if(mk[i]>0)
        mq[i]=temp;
    }
    if(n>2&&mk[n]>0)
        mq[n]=1;
}
void remove(int n)
{
    int temp=0;
    while(n%2==0)
    {
        temp++;
        n=n/2;
    }
    if(temp>0)
    mq[2]=mq[2]-temp;
    for(int i=3;i*i<=n;i+=2)
    {
        temp=0;
        while(n%i==0)
        {
            temp++;
            n=n/i;
        }
        if(temp>0)
        mq[i]=mq[i]-temp;
    }
    if(n>2)
        mq[n]=1;
}
int main()
{


    addpairk(75);
    addpairq(75);
    remove(15);
    map<int,int>  :: iterator it;
    for(it=mq.begin();it!=mq.end();it++)
    {
    	cout<<it->first<<" "<<it->second<<endl;
	}
	
    
	return 0;
}
