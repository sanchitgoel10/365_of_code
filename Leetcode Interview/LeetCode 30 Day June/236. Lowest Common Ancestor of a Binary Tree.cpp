/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Watch video
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root == p || root == q)
            return root;
        // Check if left contains p or q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // Check if right contains p or q
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if left and right containsp or q the it'sthe LCA
        if(left && right)
            return root;
        return left ? left : right;
    }
};