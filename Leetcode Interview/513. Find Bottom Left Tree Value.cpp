class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> v;
        v.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            v.clear();
            int s=q.size();
            while(s--){
                TreeNode*curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return v[0];
    }
};