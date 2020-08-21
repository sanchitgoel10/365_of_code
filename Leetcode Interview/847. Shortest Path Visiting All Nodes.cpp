/*
Good question.
  First, 0x3f3f3f3f is a very large number in int32, and most int32 value cannot exceed this. (0x3f3f3f3f = 1061109567)
  Second, we can initialize arrays easily using "memset(arr, 0x3f, sizeof(arr))". Because memset function sets values by "byte", and each byte in 0x3f3f3f3f is 0x3f! (whereas 0x7fffffff does not have this characteristic)
  Third, compared with 0x7ffffff, 0x3f3f3f3f does not encounter integer overflow at times. For example, in shortest path algorithm, if we want to update the "dist[v]", we need to check "if (dist[u] + path[u][v] < dist[v] )". If path[u][v] is 0x7fffffff, then "dist[u] + path[u][v]" becomes a negative integer due to integer overflow, whereas 0x3f3f3f3f avoids this situation.
Yes, to avoid overflow. I'm sorry that I mistyped 0x3f3f3f (it is actually 0x3f3f3f3f and I just updated my post). 0x3f3f3f3f is a 4 byte value that equals to 1061109567 in decimal. A integer normally has 4 bytes, so every byte of the integer in the "arr" becomes 0x3f if we use "memset(arr, 0x3f, sizeof(arr))". For the last question, yes I mean that.

(If the data range in the problem description is small, like 12 or 15. The problem is most likely to be solved by "state compression dp" )

In my solution,
  dis[x][y] represents the minimun distance between node x and node y.
  dp[group][dst] represents the shortest distance that a man could walk through all nodes in the "group", and finally finished at the node "dst" ("dst" is one of the node in "group").

To calculate dp[][], enumerate every possible state (which is "group". For example, If group only has node 0 and node 2, the value of group is 101 in binary). Pick a node that is in the "group"(for example, node u), and pick a node that is not in the "group"(for example, node v). Then update dp[group+v][v] by getting the minimum value between dp[group+v][v] and dp[group][u] + dis[u][v].
*/
class Solution {
public:
    
    int dis[15][15];
    int dp[1<<13][13];
    
    void floyd(int n) {          //floyd warshal
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    }
    int DP(int n) {
        memset(dp, 0x3f, sizeof(dp));
        for (int i=0; i<n; i++)
            dp[1<<i][i] = 0;                      //group with only itself
        for (int group=1; group<(1<<n); group++)
            for (int u=0; u<n; u++)          
                for (int v=0; v<n; v++) {
                    int src = 1 << u, dst = 1 << v;
                    if ((group & src) && !(group & dst))   //contains src but not dst in group
                        dp[group|dst][v] = min(dp[group][u] + dis[u][v], dp[group|dst][v]);
                }
        int min_dis = 0x3f3f3f3f;
        for (int i=0; i<n; i++)     
            min_dis = min(dp[(1<<n)-1][i], min_dis);   //min of groups with all at different ending point
        return min_dis;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(dis, 0x3f, sizeof(dis));
        for (int i=0; i<n; i++) {
            int to_size = graph[i].size();
            for (int j=0; j<to_size; j++) {
                int u = i, v = graph[i][j];
                dis[u][v] = 1;                 //building graph
            }
        }
        floyd(n);
        int min_dis = DP(n);
        return min_dis;
    }
};
