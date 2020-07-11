class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        return (root->left==root->right&&root->val==0)?NULL:root;
    }
};