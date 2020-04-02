/*This problem is trying to find the cheapest way of moving cards to get them into a correct order.

Permutation
Suppose we have red, green, and blue cards with numbers 1 to 4.

All the same colour have to be together, and inside each group, the numbers must be sorted.

Therefore there are 3!=3*2*1=6 possible correct final orders:

R1 R2 R3 R4 B1 B2 B3 B4 G1 G2 G3 G4  (RBG)
R1 R2 R3 R4 G1 G2 G3 G4 B1 B2 B3 B4  (RGB)
B1 B2 B3 B4 R1 R2 R3 R4 G1 G2 G3 G4  (BRG)
G1 G2 G3 G4 R1 R2 R3 R4 B1 B2 B3 B4  (GRB)
B1 B2 B3 B4 G1 G2 G3 G4 R1 R2 R3 R4  (BGR)
G1 G2 G3 G4 B1 B2 B3 B4 R1 R2 R3 R4  (GBR)
Each order is determined by a permutation of the colours (shown in brackets).

This solution works by iterating over each permutation of the colours.

For each permutation it computes in v the correct position of each card for the given permutation. The function go is used to compute the smallest number of moves to place v into sorted order.

For example, if we have chosen the permutation (RGB), and the cards were originally in order:

R1 R2 R3 R4 G1 G2 G3 G4 B1 B2 B4 B3
Then v would be computed as

0  1  2  3  4  5  6  7  8  9  11 10
and go would determine that one move was needed to sort the cards.

Counting moves to sort
The go function works out the smallest number of moves by computing the longest increasing subsequence in v.

Once we have found the LIS, then we know we have to move every card that is not in this subsequence, and so the number of moves is t-length of LIS. (t is the number of cards)

In our example, the longest increasing subsequence would be:

     0  1  2  3  4  5  6  7  8  9 10
which is of length 11, so the answer is 12-11=1

*/





#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int c,n;

int lis(){
	int size = c*n;
	int dp[size];

	for(int i=0;i<size;i++){dp[i]=1;}
	
	for(int i=1;i<size;i++){
		for(int j=0;j<i;j++){
			if(v[i] > v[j]){dp[i] = max(dp[i],dp[j]+1);}
		}
	}
	int res=0;
	for(int i=0;i<size;i++){res=max(res,dp[i]);}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	cin>>c>>n;

	int color[c*n],num[c*n];
	for(int i=0;i<c*n;i++){
		cin>>color[i]>>num[i];
	}

	vector<int> per;
	for(int i=0;i<c;i++){per.push_back(i);}

	int ans = INT_MAX;
	do{
		int cnt=0;
		int arr[c][n];
		for(int i=0;i<c;i++){
			for(int j=0;j<n;j++){
				arr[per[i]][j]=cnt++;
			}
		}
		v.clear();
		for(int i=0;i<c*n;i++){
			v.push_back(arr[color[i]-1][num[i]-1]);
		}
		int x = lis();

		ans = min(ans,c*n - x);
	}while(next_permutation(per.begin(),per.end()));
	cout<<ans<<endl;
}