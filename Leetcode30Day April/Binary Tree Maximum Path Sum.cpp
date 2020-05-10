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
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans;
    
    int dfs(TreeNode*root){
        if(root==NULL)return 0;
        
        int x=dfs(root->left);
        int y=dfs(root->right);
        
        ans=max(ans,x+y+root->val);
        
        return max(0,root->val+max(x,y));
    }
    
public:
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        dfs(root);
        return ans;
    }
};