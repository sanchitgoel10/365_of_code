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

//O(N) method    https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
/*This is so named , since it works on graphs with edge weights 0 and 1. Let's take a point of execution of BFS when you are at an arbitrary vertex "u" having edges with weight 0 and 1. Similar to Dijkstra , we only put a vertex in the queue if it has been relaxed by a previous vertex (distance is reduced by travelling on this edge) and we also keep the queue sorted by distance from source at every point of time.

Now , when we are at "u" , we know one thing for sure : Travelling an edge (u,v) would make sure that v is either in the same level as u or at the next successive level. This is because the edge weights are 0 and 1. An edge weight of 0 would mean that they lie on the same level , whereas an edge weight of 1 means they lie on the level below. We also know that during BFS our queue holds vertices of two successive levels at max. So, when we are at vertex "u" , our queue contains elements of level L[u] or L[u] + 1. And we also know that for an edge (u,v) , L[v] is either L[u] or L[u] + 1. Thus , if the vertex "v" is relaxed and has the same level , we can push it to the front of our queue and if it has the very next level , we can push it to the end of the queue. This helps us keep the queue sorted by level for the BFS to work properly.

But, using a normal queue data structure , we cannot insert and keep it sorted in O(1). Using priority queue cost us O(logN) to keep it sorted. The problem with the normal queue is the absence of methods which helps us to perform all of these functions :

Remove Top Element (To get vertex for BFS)
Insert At the beginning (To push a vertex with same level)
Insert At the end (To push a vertex on next level)
Fortunately, all of these operations are supported by a double ended queue (or deque in C++ STL). Let's have a look at pseudocode for this trick :
*/
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        deque<pair<int, int>> q{{0, 0}};  // for the pair, the first element is the cell position, the second is the path cost to this cell
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<int> visited;
        
        int res = 0;
        while(!q.empty())
        {
            auto t = q.front(); 
            q.pop_front();

            int curi = t.first / n, curj = t.first % n;
            if (visited.insert(t.first).second)  // If we have never visited this node, then we have the shortest path to this node
                res = t.second;
            
            if (curi == m-1 && curj == n-1)
                return res;
            
            for (auto dir: dirs)
            {
                int x = curi + dir[0];
                int y = curj + dir[1];
                int pos = x * n + y;
                if (x<0 || x>=m || y<0 || y>=n || visited.count(pos)) continue;
                
                int cost;
                if (grid[curi][curj] == 1 && dir[0] == 0 && dir[1] == 1) cost = 0;
                else if (grid[curi][curj] == 2 && dir[0] == 0 && dir[1] == -1) cost = 0;
                else if (grid[curi][curj] == 3 && dir[0] == 1 && dir[1] == 0) cost = 0;
                else if (grid[curi][curj] == 4 && dir[0] == -1 && dir[1] == 0) cost = 0;
                else cost = 1;
                
                if (cost == 1)
                    q.push_back({pos, t.second + cost});
                else
                    q.push_front({pos, t.second + cost});
            }
        }
        return res;
    }
};