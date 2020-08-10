class Solution {
public:
    string ans="|";
    void solve(TreeNode*root,string s){
        if(!root)return;
        if(!root->left&&!root->right){
            ans=min(ans,char(root->val+'a')+s);   //front me add hua hai
        }
        solve(root->left,char(root->val+'a')+s);
        solve(root->right,char(root->val+'a')+s);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};