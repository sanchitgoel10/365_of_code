class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;         //base case
        if(!p&&q||!q&&p)return false;   //one null other not null
        if(p->val!=q->val)return false;   //value at node not same
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);    //both left and right subtree should be same
    }
};