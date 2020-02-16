#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
char a[1000000];
int main(){
  int i,j,k,m,n,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&k);
      a[i]=k;
    }
    for(i=n-2;i>=0;i--){
      if( a[i]<a[i+1] )
	break;
    }
    if( i==-1 ){
      printf("%d\n",-1);
      continue;
    }
    for(j=i+1;j<n;j++){
      if( a[j]<=a[i] )
	break;
    }
    swap(a[i],a[j-1]);
    sort(a+i+1,a+n);
    for(i=0;i<n;i++)
      printf("%d",a[i]);
    printf("\n");
  }
}