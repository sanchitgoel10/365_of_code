#include<bits/stdc++.h>
using namespace std;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

bool valid(int x,int y,int r,int c){
    if(x>=0&&x<r&&y>=0&&y<c)return 1;
    return 0;
}

void dfs(int**visited,vector<vector<char>>& grid,int x,int y,int r,int c){
    
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int newx=x+fx[i];
        int newy=y+fy[i];
        if(valid(newx,newy,r,c)&&grid[newx][newy]=='1'&&!visited[newx][newy]){
            dfs(visited,grid,newx,newy,r,c);
        }
    }
    
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)return 0;
        int r=grid.size();
        int c=grid[0].size();
        //cout<<r<<" "<<c<<endl;
        int**visited = new int*[r];
        for(int i=0;i<r;i++){
            visited[i]=new int[c];
            for(int j=0;j<c;j++){
                visited[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(visited,grid,i,j,r,c);
                    ans++;
                }
            }
        }
        return ans;
    }
};