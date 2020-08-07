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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,set<int>>> nodes;          //map of x then map of y then set of values
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto n=q.front();
            q.pop();
            int x=n.second.first;
            int y=n.second.second;
            TreeNode*curr=n.first;
            nodes[x][y].insert(curr->val);
            if(curr->left){
                q.push({curr->left,{x-1,y+1}});
            }
            if(curr->right){
                q.push({curr->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x:nodes){              //in increasing order of x coordinate
            vector<int> col;
            for(auto y:x.second){          //in increasing order of y coordinate
                col.insert(col.end(),y.second.begin(),y.second.end()); //if same then increasing order of value
            }
            ans.push_back(col);
        }
        return ans;
    }
};