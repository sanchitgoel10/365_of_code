/*
The solution above is slow, and BFS can help to make sure we process a single cell only once (well, twice in our case to scan for the land first).

Here, we find our land cells and put surrounding water cells in the queue. We mark water cells as visited and continue the expansion from land cells until there are no more water cells left. In the end, the number of steps in DFS is how far can we go from the land.


IMage hai discussion me mast
*/

int maxDistance(vector<vector<int>>& g, int steps = 0) {
  queue<pair<int, int>> q, q1;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 1)
        q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });

  while (!q.empty()) {    //simultaneous bfs on all points 
    ++steps;
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      q.pop();
      if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
        g[i][j] = steps;
        q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
      }
    }
    swap(q1, q);
  }
  return steps == 1 ? -1 : steps - 1;
}