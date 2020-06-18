/*
The problem could also be solved in-place. O(M \times N)O(M×N) space complexity could be too expensive when the board is very large. We only have two states live(1) or dead(0) for a cell. We can use some dummy cell value to signify previous state of the cell along with the new changed value.

For e.g. If the value of the cell was 1 originally but it has now become 0 after applying the rule, then we can change the value to -1. The negative sign signifies the cell is now dead(0) but the magnitude signifies the cell was a live(1) cell originally.

Also, if the value of the cell was 0 originally but it has now become 1 after applying the rule, then we can change the value to 2. The positive sign signifies the cell is now live(1) but the magnitude of 2 signifies the cell was a dead(0) cell originally.


CODE KE NICHE DEKH


The above is the idea below is implemented in a different manner
00 :die->die
10 :die->alive
01 :alive->die
11 :alive->alive
The left digit means next state, and right digit means previous state.
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int d[][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int live = 0;
                for(int k = 0; k < 8; k++){
                    int x = d[k][0] + i;
                    int y = d[k][1] + j;
                    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if(board[x][y] & 1) {          //interacting with the original bit only
                        live++;
                    }
                }
                if(board[i][j] == 0) {
                    if(live == 3){
                        board[i][j] = 2; // 2 : (10)
                    }
                }
                else {
                    if(live < 2 || live > 3){
                        board[i][j] = 1; // 1 : (01)
                    }else{
                        board[i][j] = 3; // 3 : (11)   
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                board[i][j] >>=1;                      //removing extra bits
            }
        }
    }
}
/*So far we've only addressed one of the follow-up questions for this problem statement. We saw how to perform the simulation according to the four rules in-place i.e. without using any additional memory. The problem statement also mentions another follow-up statement which is a bit open ended. We will look at two possible solutions to address it. Essentially, the second follow-up asks us to address the scalability aspect of the problem. What would happen if the board is infinitely large? Can we still use the same solution that we saw earlier or is there something else we will have to do different? If the board becomes infinitely large, there are multiple problems our current solution would run into:

It would be computationally impossible to iterate a matrix that large.
It would not be possible to store that big a matrix entirely in memory. We have huge memory capacities these days i.e. of the order of hundreds of GBs. However, it still wouldn't be enough to store such a large matrix in memory.
We would be wasting a lot of space if such a huge board only has a few live cells and the rest of them are all dead. In such a case, we have an extremely sparse matrix and it wouldn't make sense to save the board as a "matrix".
Such open ended problems are better suited to design discussions during programming interviews and it's a good habit to take into consideration the scalability aspect of the problem since your interviewer might be interested in talking about such problems. The discussion section already does a great job at addressing this specific portion of the problem. We will briefly go over two different solutions that have been provided in the discussion sections, as they broadly cover two main scenarios of this problem.

One aspect of the problem is addressed by a great solution provided by Stefan Pochmann. So as mentioned before, it's quite possible that we have a gigantic matrix with a very few live cells. In that case it would be stupidity to save the entire board as is.

If we have an extremely sparse matrix, it would make much more sense to actually save the location of only the live cells and then apply the 4 rules accordingly using only these live cells.

Let's look at the sample code provided by Stefan for handling this aspect of the problem.


Essentially, we obtain only the live cells from the entire board and then apply the different rules using only the live cells and finally we update the board in-place. The only problem with this solution would be when the entire board cannot fit into memory. If that is indeed the case, then we would have to approach this problem in a different way. For that scenario, we assume that the contents of the matrix are stored in a file, one row at a time.

In order for us to update a particular cell, we only have to look at its 8 neighbors which essentially lie in the row above and below it. So, for updating the cells of a row, we just need the row above and the row below. Thus, we read one row at a time from the file and at max we will have 3 rows in memory. We will keep discarding rows that are processed and then we will keep reading new rows from the file, one at a time.
*/