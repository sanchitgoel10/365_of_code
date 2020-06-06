
//Idea: The boundary ones that are on the 1st row,1st cloumn last row last column will breach boundary and
// the ones connected to them will also breach it,therfore count all points which will breach and then substract from total

class Solution {
public:
    const int fx[4]={+1,-1,+0,+0};
    const int fy[4]={+0,+0,+1,-1};
    void dfs(vector<vector<int>>&A,vector<vector<int>>&vis,int i,int j,int n,int m){
        vis[i][j]=1;
        for(int t=0;t<4;t++){
            int ni=i+fx[t];
            int nj=j+fy[t];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&!vis[ni][nj]&&A[ni][nj]){
                dfs(A,vis,ni,nj,n,m);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int total=0;                //total ones
        int n=A.size();
        int m=A[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); //visited matrix

        for(int j=0;j<m;j++){
            if(!vis[0][j]&&A[0][j]){  //1st row
                dfs(A,vis,0,j,n,m);
            }
            if(!vis[n-1][j]&&A[n-1][j]){  //last row
                dfs(A,vis,n-1,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0]&&A[i][0]){     //1st column
                dfs(A,vis,i,0,n,m);
            }
            if(!vis[i][m-1]&&A[i][m-1]){   //last column
                dfs(A,vis,i,m-1,n,m);
            }
        }
        int not_poss=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]){
                    total++;
                    if(vis[i][j])not_poss++; //the ones which can cross boundary
                }
            }
        }
        return total-not_poss;
    }
};