/*
Build a graph where grid[i][j] is connected to all the four side-adjacent cells with weighted edge. the weight is 0 if the sign is pointing to the adjacent cell or 1 otherwise.
Do BFS from (0, 0) visit all edges with weight = 0 first. the answer is the distance to (m -1, n - 1).
Done dijkastras
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        using ti = tuple<int, int, int>;   //<cost,x,y>
        priority_queue<ti, vector<ti>, greater<ti>> pq;   //min heap
        vector<vector<int>> vis(m, vector<int>(n, 0));
        pq.emplace(0, 0, 0);              //start point
        while (pq.size()) {                            //dijkastras slgo
            auto [cost, x, y] = pq.top(); pq.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == m - 1 && y == n - 1) return cost;   //reached
            for (int i = 0; i < 4; ++i) {
                auto &[dx, dy] = dir[i];
                int nx = dx + x, ny = dy + y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    if (i == grid[x][y] - 1) {              //there is a route in this dirn
                        pq.emplace(cost, nx, ny);
                    } else {                                //the other three directions
                        pq.emplace(cost + 1, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};