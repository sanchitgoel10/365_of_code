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

int good(TreeNode*root,int m){
    
    if(root==NULL)return 0;
    
    int ans1=good(root->right,max(root->val,m));
    int ans2=good(root->left,max(root->val,m));
    
    int ans=0;

    if(root->val>=m){
        ans=1;
    }
    return ans+ans1+ans2;
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans=good(root,root->val);
        return ans;
    }
};