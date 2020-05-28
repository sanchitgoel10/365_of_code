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
    unordered_map<int,int> m;
    int sum(TreeNode*root){
        if(!root)return 0;
        int ans=root->val;
        int l=sum(root->left);
        int r=sum(root->right);
        ans+=l;
        ans+=r;
        m[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int x=sum(root);
        vector<int> ans;
        int mx=-1;
        for(auto i:m){
            if(i.second>mx){
                ans.clear();
                mx=i.second;
                ans.push_back(i.first);
            }else if(i.second==mx){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};