class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int inf=1e9;
        K++;
        vector<vector<int>> ans(n,vector<int>(K+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<=K;j++){
                ans[i][j]=inf;
            }
        }
        ans[src][0]=0;
        for(int i=1;i<=K;i++){
            for(int j=0;j<n;j++){
                ans[j][i]=ans[j][i-1];      //one less stop that is been already calculated
            }
            for(auto &v:flights){
                ans[v[1]][i]=min(ans[v[1]][i],ans[v[0]][i-1]+v[2]);        //increasing one stop at every possible path
            }
        }
        if(ans[dst][K]==inf)return -1;
        return ans[dst][K];
    }
};