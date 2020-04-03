#include <bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int longestSubsequenceCommonSegment(int k, string s1,  
                                           string s2) 
{ 
    // length of strings 
    int n = s1.length(); 
    int m = s2.length(); 
  
    // declare the lcs and cnt array 
    int lcs[n + 1][m + 1]; 
    int cnt[n + 1][m + 1]; 
  
    // initialize the lcs and cnt array to 0 
    memset(lcs, 0, sizeof(lcs)); 
    memset(cnt, 0, sizeof(cnt)); 
  
    // iterate from i=1 to n and j=1 to j=m 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) { 
  
            // stores the maximum of lcs[i-1][j] and lcs[i][j-1] 
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]); 
  
            // when both the characters are equal 
            // of s1 and s2 
            if (s1[i - 1] == s2[j - 1]) 
                cnt[i][j] = cnt[i - 1][j - 1] + 1;  
  
            // when length of common segment is 
            // more than k, then update lcs answer  
            // by adding that segment to the answer 
            if (cnt[i][j] >= k) { 
  
                // formulate for all length of segments 
                // to get the longest subsequence with  
                // consecutive Common Segment of length  
                // of min k length 
                for (int a = k; a <= cnt[i][j]; a++)  
  
                    // update lcs value by adding segment length 
                    lcs[i][j] = max(lcs[i][j],  
                                    lcs[i - a][j - a] + a); 
                  
            } 
        } 
    } 
  
    return lcs[n][m]; 
}

int main() {
	// your code goes here
	FastRead;
	int k;
	while(cin>>k){
	    if(k==0) break;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    int ans=longestSubsequenceCommonSegment(k,s1,s2);
	    cout<<ans<<endl;
	}
	return 0;
}
