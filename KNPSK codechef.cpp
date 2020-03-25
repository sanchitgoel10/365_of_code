#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int N,i, tmp, tmp2, tot=0,j;
    cin>>N;
    vector<int>ones,twos;
    for(i=0;i<N;i++)
    {
        cin>>tmp>>tmp2;
        if(tmp==1)
            ones.push_back(tmp2);
        else
            twos.push_back(tmp2);
        tot+= tmp;
    }
    sort(ones.begin(),ones.end());
    sort(twos.begin(),twos.end());
    int arr[tot+1];
    i=ones.size()-1;
    j=twos.size()-1;
    arr[0]=0;
    if(i>=0)
    {
        arr[1] = ones[i];
    }
    else
    {
        arr[1] = 0;
    }
    i--;
    cout<<arr[1] <<" ";
    for(int k=1;k<tot;k++){
        int p=arr[k];
        int q=arr[k-1];
        if(i>=0)
            p+=ones[i];    //using the best cost of weight 1
        if(j>=0)
            q+=twos[j];    // using the best 2 by discarding 1 
        arr[k+1]=max(p,q);
        if(p>=q){
            i--;
        }else{
            i++;
            j--;
        }
        cout<<arr[k+1]<<" ";
    }
    
    
	return 0;
}
