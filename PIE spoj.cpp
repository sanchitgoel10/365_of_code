#include <bits/stdc++.h>
using namespace std;
int n,f;
long double pi=3.14159265358979323846264338327950;
int func(long double num,long double array[])
{
    int fr=0;
    for (int i=0; i<n; i++)
        fr+=(int)(array[i]/num);
    if (fr>=f)
        return 1;
    else
        return 0;
}
long double bs(long double array[])
{
    long double ini=0,last=array[n-1],max=0.0;
    while (last - ini >= 1e-3)          //error given
    {
        long double mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            ini=mid;
        }
        else
            last=mid;
    }
    return ini;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&f);
        f++;
        int array1[n];
        for (int i=0; i<n; i++)
            scanf("%d",&array1[i]);
        long double array[n];
        sort(array1,array1+n);
        for (int i=0; i<n; i++)
            array[i]=array1[i]*array1[i]*pi;
        long double k=bs(array);
        printf("%.4Lf\n",k);
    }
    return 0;
}