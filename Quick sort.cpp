#include <bits/stdc++.h>
using namespace std;

int part(int*arr,int s,int e){
    int piv=arr[e];
    int pi=s;
    for(int i=s;i<e;i++){
        if(arr[i]<=piv){
            swap(arr[i],arr[pi]);
            pi++;
        }
    }
    swap(arr[pi],arr[e]);
    return pi;
}

void quicksort(int* arr,int s,int e){
    if(s<e){
        int pi=part(arr,s,e);
        quicksort(arr,s,pi-1);
        quicksort(arr,pi+1,e);
    }
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0,e=n;
    quicksort(arr,s,e-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
	return 0;
}
