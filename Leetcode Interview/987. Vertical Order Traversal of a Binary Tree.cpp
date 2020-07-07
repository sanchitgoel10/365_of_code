/*
In this problem, if two nodes are in the same row and column, the order should be from small to large.

The idea is to build a mapping from coordinates to nodes.

BFS

Build the mapping using a queue of pairs of nodes and corresponding coordinates.
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;             //map and set keeps thing sorted
        queue<pair<TreeNode*, pair<int, int>>> todo; 
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
//DFS

//Build the mapping recursively.

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        traverse(root, 0, 0, nodes);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
private:
    void traverse(TreeNode* root, int x, int y, map<int, map<int, set<int>>>& nodes) {
        if (root) {
            nodes[x][y].insert(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};