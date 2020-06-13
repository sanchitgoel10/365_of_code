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
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2]-1;    //-1 kyuki question me mention kara hai 
    }
   //[max if I go left,max if I go right,ans]
    vector<int> dfs(TreeNode* root) {
        if (!root) return { 0, 0, 0};
        vector<int> left = dfs(root->left), right = dfs(root->right);
        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));  //left[1] matlab mene left turn liya aur left node se pucha tu right leta to kitna aata
        return {left[1] + 1, right[0] + 1, res};
    }
};