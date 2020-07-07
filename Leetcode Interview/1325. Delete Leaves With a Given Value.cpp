/*
Recursively call removeLeafNodes on the left and right.
If root.left == root.right == null and root.val == target,
the root node is now a leaf with value = target, we return null.
Otherwise return root node itself.
As we need to remove a parent if it becomes a leaf, we need to process children first, then "visit" the parent (post-order traversal).
*/
TreeNode* removeLeafNodes(TreeNode* r, int target) {
    if (r == nullptr) return nullptr;
    r->left = removeLeafNodes(r->left, target);
    r->right = removeLeafNodes(r->right, target);
    return (r->left == r->right && r->val == target) ? nullptr : r;
}