/*Use a sliding window to find the maximum sum of length K. Initially the sliding window's sum is set to the accumulated sum of the last K digits of A. Then as the window "slides", we increment the sum by A[i] and decrement the sum by A[j].

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12

As the window "slides":

Each i-th element of A highlighted in green is included in the sliding window'ssum
Each j-th element of A in red text is removed from the sliding window's sum
*/

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int mx=0;
        for(int i=n-k;i<n;i++){      //sum of last k elements
            mx+=card[i];
        }
        int sum=mx;
        int i=0;
        int j=n-k;
        while(k--){
            sum+=card[i++];     //shift one i ahead
            sum-=card[j++];     //delete on j 
            mx=max(mx,sum);
        }
        return mx;
    }
};
//Time O(n)





//Sasta in contest dp solution with tle
class Solution {
public:
    int solve(vector<vector<int>>&dp,int i,int j,int k,vector<int>&card){
        if(k==0)return 0;
        if(i==j)return card[i];
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=max(solve(dp,i+1,j,k-1,card)+card[i],solve(dp,i,j-1,k-1,card)+card[j]);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(dp,0,n-1,k,cardPoints);
    }
};
//Time O(n2)