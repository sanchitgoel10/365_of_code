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

private:
    TreeNode* Helper(vector<int>& preorder,int& id,int parent_value){
        if(id==preorder.size()||preorder[id]>parent_value){
            return NULL;
        }
        int root_value=preorder[id++];
        TreeNode*root = new TreeNode(root_value);
        root->left=Helper(preorder,id,root_value);     //for left bst limit is the current root value 
        root->right=Helper(preorder,id,parent_value);  //for right bst limit is the  parent value
        
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id=0;
        TreeNode* root=Helper(preorder,id,INT_MAX);
        return root;
    }
};