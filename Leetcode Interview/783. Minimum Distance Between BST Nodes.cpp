class Solution {
public:
    
    void helper(TreeNode*node,int &pre,int &ans){
        if(!node)return;
        if(node->left)helper(node->left,pre,ans);
        if(pre>=0)ans=min(ans,node->val-pre);
        pre=node->val;
        if(node->right)helper(node->right,pre,ans);
        return;
    }
    
    int minDiffInBST(TreeNode* root) {
        int pre=-1,ans=INT_MAX;
        helper(root,pre,ans);
        return ans;
    }
};