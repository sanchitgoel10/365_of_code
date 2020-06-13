/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode*root,TreeNode*minnode,TreeNode*maxnode){
        if(!root)return 1;
        if((minnode&&root->val<=minnode->val)||(maxnode&&root->val>=maxnode->val))
            return 0;
        return solve(root->left,minnode,root)&&solve(root->right,root,maxnode);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};