class Solution {
public:
    int ans=INT_MIN;
    
    void helper(TreeNode*node,int maxtill,int mintill){
        if(!node)return;
        ans=max(ans,max(abs(maxtill-node->val),abs(mintill-node->val)));
        helper(node->left,max(maxtill,node->val),min(mintill,node->val));
        helper(node->right,max(maxtill,node->val),min(mintill,node->val));
        return;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};