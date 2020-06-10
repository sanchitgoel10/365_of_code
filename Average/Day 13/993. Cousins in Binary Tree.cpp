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

int Find(TreeNode*root,int x,int d){
    if(root==NULL){
        return -1;
    }
    if((root->val)==x)return d;
    
    int d1=Find(root->left,x,d+1);
    
    if(d1!=-1)return d1;
    
    int d2=Find(root->right,x,d+1);
    
    return d2;
}

int Findp(TreeNode*root,int x,int parent){
    if(root==NULL)return 0;
    
    if((root->val)==x)return parent;
    
    int p1=Findp(root->left,x,root->val);
    if(p1!=0)return p1;
    
    int p2=Findp(root->right,x,root->val);
    
    return p2;
    
    
}

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int d1=Find(root,x,0);
        int d2=Find(root,y,0);
        
        int p1=Findp(root,x,-1);
        int p2=Findp(root,y,-1);
        
        if(d1==d2&&p1!=p2)return 1;
        return 0;
    }
};