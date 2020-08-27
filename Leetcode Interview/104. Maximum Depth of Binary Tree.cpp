class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int ans=1;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return ans+max(l,r);
    }
};