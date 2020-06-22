/*In general:
dp(left, right )= min( max(arr[left .. i] ) * max(arr[i+1 .. right]) + dp(left,i) +dp(i+1,right) ) where i go from left to right-1

In our previous formula i divide the root in [left .. i] left subtree and [i+1.. right] right subtree.
*/
class Solution {
public:
    int memo[41][41];
    int maxi[41][41];
    
    int dp(int left,int right){
        if(left==right)return 0; //leaf node
        if(memo[left][right]!=-1)return memo[left][right];
        
        int ans = 1<<30;
        
        for(int i=left;i<right;i++)
            ans= min(ans, maxi[left][i] * maxi[i+1][right] + dp(left,i) + dp(i+1,right) );
        
        memo[left][right]=ans;
        return ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        memset(memo,-1,sizeof(memo));
        for(int i=0;i<arr.size();i++){
            maxi[i][i] = arr[i];
            for(int j=i+1;j<arr.size();j++)
                maxi[i][j] = max(maxi[i][j-1], arr[j]);
        }
        
        return dp(0,arr.size()-1);
    }
};
/*
The second solution removes the less of pair arr[i] and arr[i + 1] which has minimum product during each iteration.
Now we think about it, each iteration actually removes a local minimum value.
For elements arr[i - 1], arr[i] and arr[i + 1] where arr[i] is the local minium.
The product added to final result is arr[i] * min(arr[i - 1], arr[i + 1])
The problem can be translated into removing all local minium values while finding the first greater element on the left and on the right.
A stack based solution from previous problems can be applied as lee215 mentioned in his post.
*/
int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }