/* 
Problem : Delish
Author : Vivek Hamirwasia
Difficulty : Easy
*/

#include<cstdio>
#include<algorithm>
#include<cmath>
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
using namespace std;

/*
   leftdp -> stores maximum and minimum from left till every index i
   rightdp -> stores maximum and minimum from right till every index i
*/

long long int leftdp[1000004][2],rightdp[1000004][2], a[1000004];
int main()
{
       
	int n,t;
	// Taking input
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	for(int i = 0; i < n; i++)
	    scanf("%lld",&a[i]);

	// Initializing the max and min from left to the first element from the left
	leftdp[0][0] = a[0];
	leftdp[0][1] = a[0];

	for(int i = 1; i < n; i++)
	{
	    //updating the max and min from left upto i using dp
	    leftdp[i][0] = max(leftdp[i-1][0],0) + a[i];
	    leftdp[i][1] = min(leftdp[i-1][1],0) + a[i];	
	}


	// Initializing the max and min from right to the first element from the left
	rightdp[n-1][0] = a[n-1];
	rightdp[n-1][1] = a[n-1];
	for(int i = n-2; i >= 0; i--)
	{
	    //updating the max and min from right upto i using dp
	    rightdp[i][0] = max(rightdp[i+1][0],0) + a[i];
	    rightdp[i][1] = min(rightdp[i+1][1],0) + a[i];	
	}

	long long int ans = 0;
	for(int i = 0; i < n-1; i++)
	{
	   // absolute difference between minimum from left upto i and maximum from right upto i+1
	   ans = max(ans,abs(leftdp[i][0] - rightdp[i+1][1]));
	   // absolute difference between maximum from left upto i and minimum from right upto i+1
	   ans = max(ans,abs(leftdp[i][1] - rightdp[i+1][0]));
	}
	printf("%lld\n",ans);
	}
        return 0;
}
