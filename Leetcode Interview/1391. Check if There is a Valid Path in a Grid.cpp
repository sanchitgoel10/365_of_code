class Solution {
public:
	bool help(int i,int j,int n,int m,vector<vector<int>> &dp,vector<vector<int>>& grid,char last)
	{
		if(i<0||i>=n||j<0||j>=m||dp[i][j])return false;//handling the corner cases, dp represents if a cell is visited or not
		if(last=='l'&&(grid[i][j]==2||grid[i][j]==3||grid[i][j]==5))return false;
		else if(last=='d'&&(grid[i][j]==1||grid[i][j]==3||grid[i][j]==4))return false;
		else if(last=='r'&&(grid[i][j]==2||grid[i][j]==4||grid[i][j]==6))return false;
		else if(last=='u'&&(grid[i][j]==1||grid[i][j]==5||grid[i][j]==6))return false;
		//character last will tell us the direction from where we are reaching the current cell
		//e.g, if last=='l' it means we are reching the current cell from the left cell
		//above 4 conditions are checking whether it is possible to reach the current cell from the last cell or not
		//e.g, if last=='l' and current cell is street 1 or 4 or 6 then only we can continue
		else if(i==n-1&&j==m-1)return true;//we have reached the last cell and can return true
		dp[i][j]=1;//marking current cell as visited
		switch(grid[i][j])
		{
			case 1:return help(i,j-1,n,m,dp,grid,'l')||help(i,j+1,n,m,dp,grid,'r');
			case 2:return help(i-1,j,n,m,dp,grid,'u')||help(i+1,j,n,m,dp,grid,'d');
			case 3:return help(i,j-1,n,m,dp,grid,'l')||help(i+1,j,n,m,dp,grid,'d');
			case 4:return help(i,j+1,n,m,dp,grid,'r')||help(i+1,j,n,m,dp,grid,'d');
			case 5:return help(i,j-1,n,m,dp,grid,'l')||help(i-1,j,n,m,dp,grid,'u');
			case 6:return help(i,j+1,n,m,dp,grid,'r')||help(i-1,j,n,m,dp,grid,'u');
			default:return 0;
		}
		//there are always 2 possible ways to go from the current cell to any other cell which are being handled by above cases
		//e.g, if we are currently on street 1 we can either go to left i.e, j-1 or to right i.e, j+1
	}
	bool hasValidPath(vector<vector<int>>& grid) 
	{
		int n=grid.size(),m=grid[0].size();
		vector<vector<int>> dp(n,vector<int> (m,0));//mark a cell visited if we have visited the cell so as to avoid infinite loop
		char last;
		return help(0,0,n,m,dp,grid,last);
	}
};