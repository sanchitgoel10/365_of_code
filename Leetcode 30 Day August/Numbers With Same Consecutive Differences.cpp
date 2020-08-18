class Solution {
public:
    
    void dfs(int num,int n,int k,vector<int>&ans){
        if(n==0)ans.push_back(num);
        else{
            int d=num%10;
            if(d+k<=9)dfs(num*10+d+k,n-1,k,ans);
            if(k!=0&&d-k>=0)dfs(num*10+d-k,n-1,k,ans);
        }
        return;
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1)return {0,1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        for(int num=1;num<=9;num++)dfs(num,N-1,K,ans);
        return ans;
    }
};