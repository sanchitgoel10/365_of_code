/*
The basic idea is "keep deleting leaves layer-by-layer, until reach the root."

Specifically, first find all the leaves, then remove them. After removing, some nodes will become new leaves. So we can continue remove them. Eventually, there is only 1 or 2 nodes left. If there is only one node left, it is the root. If there are 2 nodes, either of them could be a possible root.
Time Complexity: Since each node will be removed at most once, the complexity is O(n).
*/
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    // Initialize the undirected graph
    vector<unordered_set<int>> adj(n);
    for (pair<int, int> p : edges) {
      adj[p.first].insert(p.second);
      adj[p.second].insert(p.first);
    }
    // Corner case
    vector<int> current;
    if (n == 1) {
      current.push_back(0);
      return current;
    }
    // Create first leaf layer
    for (int i = 0; i < adj.size(); ++i) {
      if (adj[i].size() == 1) {
        current.push_back(i);
      }
    }
    // BFS the graph
    while (true) {
      vector<int> next;
      for (int node : current) {
        for (int neighbor : adj[node]) {
          adj[neighbor].erase(node);
          if (adj[neighbor].size() == 1) next.push_back(neighbor);
        }
      }
      if (next.empty()) return current;          //no more layer left to remove
      current = next;
    }
  }
};