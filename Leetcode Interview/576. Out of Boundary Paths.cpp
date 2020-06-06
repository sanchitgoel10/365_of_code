class Solution {
public:
    int mod=1e9+7;
    
    int paths(int k,int i,int j,vector<vector<vector<int>>> &dp,int m,int n){
        return (i < 0 || i >= m || j < 0 || j >= n) ? 1 : dp[k][i][j];
    }
    
    int findPaths(int m, int n, int N, int i0, int j0) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        
        for (int k = 1; k <= N; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[k][i][j] = (paths(k - 1, i - 1, j,dp,m,n) + dp[k][i][j])%mod;
                    dp[k][i][j] = (paths(k - 1, i + 1, j,dp,m,n) + dp[k][i][j])%mod;
                    dp[k][i][j] = (paths(k - 1, i, j - 1,dp,m,n) + dp[k][i][j])%mod;
                    dp[k][i][j] = (paths(k - 1, i, j + 1,dp,m,n) + dp[k][i][j])%mod;
                    
                    dp[k][i][j] %= mod;
                }
            }
        }
        return dp[N][i0][j0];
    }
};

//Recusrion dp
class Solution {
public:
    long long int mem[55][55][55];
    long long int findP(int m, int n, int N, int i, int j){
         int mod=1e9+7;
        if(i<0 or j<0 or i>=m or j>=n) return 1;     //ye condiotion upar ayegi warna mem[i][j][N] wali line me error aa jayega
        if(N<=0) return 0;
        if(mem[i][j][N]!=-1) return mem[i][j][N];
        pair<int,int> p[]={{1,0},{0,1},{-1,0},{0,-1}};
        int h=0;
        for(int k=0;k<4;k++){
            int x=p[k].first+i;
            int y=p[k].second+j;
            h+=findP(m,n,N-1,x,y);
            h=h%mod;
        }
        return mem[i][j][N]=h;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        int mod=1e9+7;
        memset(mem,-1,sizeof(mem));
        long long int p=findP(m,n,N,i,j);
        return p%mod;;
    }
};