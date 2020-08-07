/*
Collect x coords in a hash map.
For each x coord, collect y coords in a set (sorted).
Go through each pair of x coords in the hash map. Ignore x coords that have less than 2 y-s.
Intersect two sets to get common y coords for this pair of x coords.
Since y coords are sorted, you only need to calculate the area for the y[k] - y[k - 1] pairs.
*/
int minAreaRect(vector<vector<int>>& points, int res = INT_MAX) {
  unordered_map<int, set<int>> x;
  for (auto p : points) x[p[0]].insert(p[1]);
  for (auto i = x.begin(); i != x.end(); ++i)
    for (auto j = next(i); j != x.end(); ++j) {
      if (i->second.size() < 2 || j->second.size() < 2) continue;
      vector<int> y;
      set_intersection(begin(i->second), end(i->second),
        begin(j->second), end(j->second), back_inserter(y));
      for (int k = 1; k < y.size(); ++k)
        res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
    }
  return res == INT_MAX ? 0 : res;
}