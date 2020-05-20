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

int count(TreeNode*root){
    if(root==NULL)return 0;
    int l=count(root->left);
    int r=count(root->right);
    return 1+l+r;
}

int countleft(TreeNode*root){      //count nodes in left sub tree
    if(root==NULL)return 0;
    int l=count(root->left);
    return l;
}

TreeNode* solve(TreeNode*root,int k){
    if(root==NULL)return NULL;
    
    int lcount=countleft(root);
    //cout<<lcount<<endl;
    if(lcount+1==k)return root;
    else if(lcount+1>k)return solve(root->left,k);
    else return solve(root->right,k-(lcount+1));     //major thing
}

class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNode*knode=solve(root,k);
        if(knode!=NULL)
            return knode->val;
        return 0;
    }
};