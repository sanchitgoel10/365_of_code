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
    int ans=0;
    
    void solve(TreeNode*root,int curr_sum){
        if(root->left==NULL&&root->right==NULL){
            ans+=curr_sum;
            return;
        }
        if(root->left)solve(root->left,curr_sum*10+root->left->val);
        if(root->right)solve(root->right,curr_sum*10+root->right->val);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        solve(root,root->val);
        return ans;
    }
};