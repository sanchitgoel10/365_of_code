/*ans[i][j] represents that the minimum cost from node src to node i using steps <= j
The initial state is ans[src][0] = 0, which means that from src to src there isn't any cost
And ans[dst][K] means the minimum cost from node src to node dst using steps <= K
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        const int INF = 1e9;
        K++;                         //stops hai K but humne edges ke hisab se k++ kardiya 
        vector<vector<int>> ans(n, vector<int>(K+1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                ans[i][j] = INF;
            }
        }
        ans[src][0] = 0;
        for(int i = 1; i <= K; i++)
        {
            for(int j = 0; j < n; j++)   //To update ans[j][i](using i steps), we copy ans[j][i-1] first
                ans[j][i] = ans[j][i-1];
            for(const vector<int>& f: flights)
            {
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2]);
            }
        }
        if(ans[dst][K] == INF) return -1;
        return ans[dst][K];
    }
};