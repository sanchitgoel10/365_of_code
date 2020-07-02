class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> temp;
            while(s--){
                TreeNode*curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//Another solution

int depth(TreeNode *root) {
    if (!root) return 0;
    return max(depth(root->left),depth(root->right))+1;
}

void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level-1);
    levelOrder(ans,node->right,level-1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> ans(d,vector<int> {});
    levelOrder(ans,root,d-1);
    return ans;
}