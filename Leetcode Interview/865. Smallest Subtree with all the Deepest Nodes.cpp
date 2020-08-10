/*
Explanatoin
Write a sub function deep(TreeNode root).
Return a pair(int depth, TreeNode subtreeWithAllDeepest)

In sub function deep(TreeNode root):

if root == null, return pair(0, null)
left = deep(root.left)
right = deep(root.left)

if left depth == right depth,
deepest nodes both in the left and right subtree,
return pair (left.depth + 1, root)

if left depth > right depth,
deepest nodes only in the left subtree,
return pair (left.depth + 1, left subtree)

if left depth < right depth,
deepest nodes only in the right subtree,
return pair (right.depth + 1, right subtree)


Complexity
Time O(N)
Space O(height)

C++
*/
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep(root).second;
    }

    pair<int, TreeNode*> deep(TreeNode* root) {
        if (!root) return {0, NULL};
        pair<int, TreeNode*> l = deep(root->left), r = deep(root->right);

        int d1 = l.first, d2 = r.first;
        return {max(d1, d2) + 1, d1 == d2 ? root : d1 > d2 ? l.second : r.second};
    }