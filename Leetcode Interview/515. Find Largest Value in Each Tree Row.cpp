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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            int mx=INT_MIN;
            while(s--){
                TreeNode* curr=q.front();
                int v=curr->val;
                q.pop();
                mx=max(mx,v);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};