/*
The first player colors a node,
there are at most 3 nodes connected to this node.
Its left, its right and its parent.
Take this 3 nodes as the root of 3 subtrees.

The second player just color any one root,
and the whole subtree will be his.
And this is also all he can take,
since he cannot cross the node of the first player.


Explanation
count will recursively count the number of nodes,
in the left and in the right.
n - left - right will be the number of nodes in the "subtree" of parent.
Now we just need to compare max(left, right, parent) and n / 2
*/
class Solution {
public:
    
    int left,right,val;
    
    int count(TreeNode*root){
        if(!root)return 0;
        int l=count(root->left),r=count(root->right);
        if(root->val==val){
            left=l,right=r;
        }
        return 1+l+r;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val=x,
        count(root);
        return max(max(left,right),n-left-right-1)>n/2; 
    }
};