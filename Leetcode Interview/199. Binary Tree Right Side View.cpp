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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int prev;        //last element of the curr level 
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(!curr){
                ans.push_back(prev);
                if(q.size()>0)q.push(NULL);
            }else{
                prev=curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return ans;
    }
};