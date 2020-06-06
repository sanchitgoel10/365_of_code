//DFS to build the back edges ( backEdge[child] = parent )
//BFS from the target as a center until the distance acheives K.
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> backEdge;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        dfs(root, backEdge, target);
        queue<TreeNode*> que;
        que.push(target);
        while(!que.empty() && K >= 0){
            int s = que.size();
            while(s--){                                  //taking out full level at a time
                TreeNode* cur = que.front();
                int val = cur->val; que.pop();
                visited.insert(cur);
                if(K == 0) res.push_back(val); 
                if(!visited.count(backEdge[cur]) && backEdge[cur]) que.push(backEdge[cur]);    //traverse above basically parents 
                if(!visited.count(cur->left) && cur->left) que.push(cur->left);       //traverse left child
                if(!visited.count(cur->right) && cur->right) que.push(cur->right);    //traverse right child
            } 
            K--;  
        }
        return res;
    }
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &backEdge, TreeNode* target){
        if(!root || (root == target)) return;
    
        if(root->left){
            backEdge[root->left] = root;
            dfs(root->left, backEdge, target);
        }
        if(root->right){
            backEdge[root->right] = root;
            dfs(root->right, backEdge, target);
        }
    }
};