class Solution {
public:
    
    int sumup(TreeNode*root,int pre,int &sum){
        if(!root)return 0;
        int curr=pre+root->val;
        return (curr==sum)+sumup(root->left,curr,sum)+sumup(root->right,curr,sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return sumup(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};