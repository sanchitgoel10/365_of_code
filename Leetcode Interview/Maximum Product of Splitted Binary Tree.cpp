/*Observation

The easiest way to do this is to check the sum of each subtree and subtract it with total sum of the tree to get sum of both the trees when the current
subtree is removed.

Solution

Let's use 1 DFS to calculate the total sum of the tree and another one to get the sum of the left subtree and the right subtree under the current node which we can use to calculate the answer for every node.

At any given point in the second dfs we can either remove the left subtree under the current node or the right subtree and make either one of them a new tree.
We can thus use the observation above to check all the subtrees in this DFS and formulate the final maximum answer.

For clarity I have here 2 seperate DFS functions, these can be merged into one as in Solution 2.
*/

static int MOD=1e9+7;
class Solution {
public:
    long long totalTreeSum=0,result=0;
    void getTotalTreeSum(TreeNode* root)    //Get total sum of the tree.
    {
        if(!root)
            return;
        totalTreeSum+=root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
       if(!root)
            return 0;
       int sumUnderLeft=SumUnder(root->left),sumUnderRight=SumUnder(root->right); //Get the sum of left and right subtree under node 'root'
       result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});    //Get the max product after making left or right subtrees as seprarate tree.
       return sumUnderLeft+sumUnderRight+root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        getTotalTreeSum(root);
        SumUnder(root);
        return result%MOD;
    }
};
/*Complexity
Space: O(h) where h is the height of the tree, at worst this can be O(n) in case of a skewed tree.
Time: O(n). We use two pass DFS's which are O(n) each

Solution 2
As stated above we can simply use the same DFS function as SumUnder to get the totalSum.

Also updated the code to make it more concise as per @lee215's comment.
*/
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