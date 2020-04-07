#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
/*
The can be solved in O(1). Let’s denote base by b and perpendicular by p. Now we have two equations b*p/2=s , b^2+p^2=h^2 This can be written as b^2+p^2+2bp = (b+p)^2 = h^2+4s and b^2+p^2-2bp = (b-p)^2 = h^2-4s. It can be seen that for solution to exist h^2-4s>=0. If the above condition is satisfied then b=(x+y)/2 and p=(x-y)/2
where, x=sqrt(h^2+4s) and y=sqrt(h^2-4s). Now print the answer as p,b,h (non-decreasing order)
*/


int main() {
    long t;
    double h,s,apb,amb,a,b,temp;
    cin>>t;
    while(t>0)
    {
        cin>>h>>s;
        apb=1.0*sqrt(1.0*(h*h+4*s));
        amb=1.0*sqrt(1.0*(h*h-4*s));
        a=1.0*(apb+amb)/2;
        b=1.0*(apb-amb)/2;
        if(a>0 && b>0)
        {
            if(b>a)
            {
                temp=b;
                b=a;
                a=temp;
            }
        printf("%0.6lf %0.6lf %0.6lf\n",b,a,h);
        }
        else
        cout<<-1<<endl;
        --t;
    }
	return 0;
}
