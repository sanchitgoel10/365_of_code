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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); 
        vector<int> curr_vec;
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(!curr){
                ans.push_back(curr_vec);
                curr_vec.clear();
                if(q.size()>0)q.push(NULL);       //pushing null signifies each level ending
                                                   //q.size()>0 means ki last level nhi hai
            }else{
                curr_vec.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return ans;
    }
};

//Recursive preorder type noice out of the box kinda stuff

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
    vector<vector<int>> ans;
    void build(TreeNode*root,int depth){
        if(!root)return;
        if(ans.size()==depth)ans.push_back(vector<int>()); //creating a new level at each depth
        ans[depth].push_back(root->val);
        build(root->left,depth+1);
        build(root->right,depth+1);
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        build(root,0);
        return ans;
    }
};