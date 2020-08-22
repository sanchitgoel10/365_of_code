/*

Prepare
I have several simple sub function to help me on this kind of problem.

valid(int x, int y), check if (x, y) is valid in the grid.
move(int x, int y), return all possible next position in 4 directions.

Explanation
Only 2 steps:

Explore every island using DFS, count its area, give it an island index and save the result to a {index: area} map.
Loop every cell == 0, check its connected islands and calculate total islands area.

Complexity
Time O(N^2)
Space O(N^2)


C++:
*/
    int N;
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        //DFS every island and give it an index of island
        int index = 2, res = 0;
        unordered_map <int, int>area;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == 1) {
                    area[index] = dfs(grid, x, y, index);
                    res = max(res, area[index++]);
                }
            }
        }
        //traverse every 0 cell and count biggest island it can conntect
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
                if (grid[x][y] == 0) {
                    unordered_set<int> seen = {};
                    int cur = 1;
                    for (auto p : move(x, y)) {
                        index = grid[p.first][p.second];
                        if (index > 1 && seen.count(index) == 0) {
                            seen.insert(index);
                            cur += area[index];
                        }
                    }
                    res = max(res, cur);
                }
        return res;
    }

    vector<pair<int, int>> move(int x, int y) {
        vector<pair<int, int>> res;
        for (auto p : vector<vector<int>> {{1, 0}, { -1, 0}, {0, 1}, {0, -1}}) {
            if (valid(x + p[0], y + p[1]))
                res.push_back(make_pair(x + p[0], y + p[1]));
        }
        return res;
    }

    int valid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int index) {
        int area = 0;
        grid[x][y] = index;
        for (auto p : move(x, y))
            if (grid[p.first][p.second] == 1)
                area += dfs(grid, p.first, p.second, index);
        return area + 1;
    }