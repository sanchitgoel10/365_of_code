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

int height(TreeNode* root){
    if(root==NULL)return 0;
    
    int l=height(root->left);
    int r=height(root->right);
    
    return 1+max(l,r);
}

int Diameter(TreeNode*root){
    if(root==NULL)return 0;
    
    int l=Diameter(root->left);
    int r=Diameter(root->right);
    
    int lh=height(root->left);
    int rh=height(root->right);
    
    return max(l,max(r,1+lh+rh));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return (Diameter(root)==0)?0:Diameter(root)-1;
    }
};