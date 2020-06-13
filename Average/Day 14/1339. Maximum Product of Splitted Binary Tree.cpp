static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
        if(!root)
            return 0;
        long long sum=SumUnder(root->left)+SumUnder(root->right)+root->val; //Get the sum of current subtree.
        result=max(result,sum*(totalTreeSum-sum));    //Get the max product after making current subtree as a separate tree
        return sum;
    }
    int maxProduct(TreeNode* root) 
    {
        totalTreeSum=SumUnder(root);
        SumUnder(root);
        return result%MOD;
    }
};