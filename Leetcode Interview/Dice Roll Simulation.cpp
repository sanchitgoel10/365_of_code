class Solution {
public:
    const int mod=1e9+7;
    vector< vector<int > > dp[20];        //20 isliye hai kyuki max roll 15 given hai
    
    int dfs(int id,int prev,int n,int len,vector<int> &rollmax){
        if(id>=n)return 1;
        
        if(dp[len][id][prev]!=-1)return dp[len][id][prev];         //len=The len of prev contigous digit roll
                                                                   //id= The ith dice roll
                                                                   //prev=previous digit roll
        int ans=0;
        for(int i=1;i<=6;i++){
            if(i==prev&&len==rollmax[i-1])continue;                //if the digit is same as prev and it has already reaches rollmax limit u cant add ans now 
            
            ans=(ans+dfs(id+1,i,n,i==prev?len+1:1,rollmax))%mod;
        }
        
        return dp[len][id][prev]=ans;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        
        for(int i=0;i<20;i++){
            dp[i].resize(n,vector<int>(7,-1));
        }
        int ans=0;
        for(int i=1;i<=6;i++){
            ans=(ans+dfs(1,i,n,1,rollMax))%mod;
        }
        return ans;
    }
};