
int a[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char pattern[11]={'C','O','D','I','N','G','N','I','N','J','A'};
int visited[MAXN][MAXN];
bool validpoint(int x,int y,int n,int m)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
int dfs(char graph[][MAXN],int x,int y,int index,int n,int m)
{
    if(index==11)
        return 1;
    
    visited[x][y]=1;
    int newx,newy,found;
    found=0;
    for(int i=0;i<8;i++)
    {
        newx=x+a[i][0];
        newy=y+a[i][1];
        
        if(validpoint(newx,newy,n,m)&&graph[newx][newy]==pattern[index]&&!visited[newx][newy])
        {
            found=found | dfs(graph,newx,newy,index+1,n,m);
        }
    }
    visited[x][y]=0;     //backtracking step
    return found;
}
int solve(char graph[][MAXN],int n, int m)
{
    int i,j,found;
    found=0;
	for( i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(graph[i][j]=='C')
            {
                found=dfs(graph,i,j,1,n,m);
                if(found)
                    break;
            }
        }
        if(found)
            break;
    }
    
    return found;
}