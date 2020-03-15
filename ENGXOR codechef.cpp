#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q,p;
        cin>>n>>q;
        int x,even=0,odd=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(__builtin_popcount(x)%2==0)
                even++;
            else
                odd++;
        }
        while(q--){
            cin>>p;
            if(__builtin_popcount(p)%2==0)
                cout<<even<<" "<<odd<<"\n";
            else
                cout<<odd<<" "<<even<<"\n";
        }
    }
}