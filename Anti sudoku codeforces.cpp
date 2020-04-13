#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		char a[10];
		for(int i=0; i<9; i++){
			scanf("%s", a);
			for(int j=0; j<9; j++){
				if(a[j]=='1')printf("2");
				else printf("%c", a[j]);
			}
			printf("\n");
		}
	}
}