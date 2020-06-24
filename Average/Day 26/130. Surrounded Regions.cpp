class Solution {
public:
    const int fx[4]={+1,-1,+0,+0};
    const int fy[4]={+0,+0,+1,-1};
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int i,int j,int n,int m){
        vis[i][j]=1;
        for(int d=0;d<4;d++){
            int ni=i+fx[d];
            int ny=j+fy[d];
            if(ni>=0&&ni<n&&ny>=0&&ny<m&&!vis[ni][ny]&&board[ni][ny]=='O'){
                dfs(board,vis,ni,ny,n,m);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        if(n==0)return;
        int m=board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,vis,i,0,n,m);
            }
            if(board[i][m-1]=='O'){
                dfs(board,vis,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,vis,0,i,n,m);
            }
            if(board[n-1][i]=='O'){
                dfs(board,vis,n-1,i,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};