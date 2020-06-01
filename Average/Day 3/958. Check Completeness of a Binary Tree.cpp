//DFS solution
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
class Solution {
public:
    int count(TreeNode*root){
        if(!root)return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool solve(TreeNode*root,int ind,int total){
        if(!root)return 1;
        if(ind>total)return 0;
        return solve(root->left,2*ind,total)&&solve(root->right,2*ind+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total=count(root);
        return solve(root,1,total);
    }
    
};
//BFS solution

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool seennull=0;         //this represents that whether we have encountered null before
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(!curr){
                seen=1;
            }else{
                if(seen)return 0;       //if encountered null before therefore not possible
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return 1;
    }
};