/*
We first paint one of the islands using DFS with color 2, so we can easily identify island #1 and island #2. Thanks @davidluoyes for pointing out that we only need to paint one island.

Then we start expanding island #2 by paining connected empty area. Each round, we increase the color (3, 4, and so on) so we can keep track of the newly painted area. This ends when we "bump" into the first island.
The fact that we are increasing the color is also useful for the backtracking, if we need to return the coordinates of the bridge.
*/
class Solution {
public:
    bool paint(vector<vector<int>>& A, int i, int j) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size() || A[i][j] != 1) return false;
        A[i][j] = 2;
        paint(A, i + 1, j); 
        paint(A, i - 1, j);
        paint(A, i, j + 1); 
        paint(A, i, j - 1);
        return true;
    }
    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
        if (i < 0 || j < 0 || i == A.size() || j == A.size()) return false;
        if (A[i][j] == 0) A[i][j] = cl + 1;
        return A[i][j] == 1;
    }  
    int shortestBridge(vector<vector<int>>& A) {
        int flag=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]){
                    paint(A,i,j);
                    flag=1;
                    break;
                }   
            }
            if(flag)break;
        }
        for (int cl = 2; ; ++cl)
            for (int i = 0; i < A.size(); ++i)
                for (int j = 0; j < A[0].size(); ++j) 
                    if (A[i][j] == cl && ((expand(A, i - 1, j, cl) || expand(A, i, j - 1, cl) || 
                        expand(A, i + 1, j, cl) || expand(A, i, j + 1, cl))))
                            return cl - 2;
    }
};