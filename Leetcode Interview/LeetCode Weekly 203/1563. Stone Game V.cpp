/*
We can simply do whats stated in the question and try all the possible partitions.
If the sum of left row is less recur on the left row.
If the sum of right row is less recur on the right row.
If the sum of both rows are equal we try recuring on both the partitions and chose the one with maximum result.
Now simply repeat step 1 for the new row
Do this until there is only 1 stone left.
We can see that there are recalculations of selected row when we perform the previous 3 steps. Thus we memoize on the row represented by i,j i.e row start and row end.
Solution
*/
class Solution {
public:
    vector<int> prefixSum;			//Stores prefixSums
    vector<vector<int>> memo;
    int dp(vector<int>& stoneValue,int i,int j)
    {
        if(i==j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j]=0;
        for(int p=i+1;p<=j;p++)		//Try each partition.
        {
	    int l=prefixSum[p]-prefixSum[i],r=prefixSum[j+1]-prefixSum[p];
	    if(l<r)		//Left part is smaller
                memo[i][j]=max(memo[i][j],l+dp(stoneValue,i,p-1));
            else if(l>r)	//Right part is smaller
                memo[i][j]=max(memo[i][j],r+dp(stoneValue,p,j));
            else	//Both parts are equal
                memo[i][j]=max(memo[i][j],l+max(dp(stoneValue,p,j),dp(stoneValue,i,p-1)));
        }
        return memo[i][j];
    }
    int stoneGameV(vector<int>& stoneValue)
    {
        memo.resize(stoneValue.size(),vector<int>(stoneValue.size(),-1));
        prefixSum.resize(stoneValue.size()+1,0);
        for(int i=0;i<stoneValue.size();i++)		//Create prefix Sums
            prefixSum[i+1]=prefixSum[i]+stoneValue[i];
        return dp(stoneValue,0,stoneValue.size()-1);
    }
};