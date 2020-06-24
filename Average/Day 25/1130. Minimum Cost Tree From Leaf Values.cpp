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