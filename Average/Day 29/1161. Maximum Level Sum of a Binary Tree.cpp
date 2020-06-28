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
    int maxLevelSum(TreeNode* root) {
        int mx=root->val;
        int lv=1;
        int ans=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(!q.empty()){                  //tracking sum according too level order
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                if(sum>mx){
                    mx=sum;
                    ans=lv;
                }
                lv++;
                sum=0;
                if(q.size())q.push(NULL);       //adding null after each level
            }else{
                if(curr->right)q.push(curr->right);
                if(curr->left)q.push(curr->left);
                sum+=curr->val;
            }
        }
        return ans;
    }
};