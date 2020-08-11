class Solution {
public:
    
    int ans=0;
    
    void helper(TreeNode*node,int v){
        if(!node->left&&!node->right){
            v*=2;
            ans+=v+node->val;
        }
        if(node->left)helper(node->left,v*2+node->val);
        if(node->right)helper(node->right,v*2+node->val);
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};