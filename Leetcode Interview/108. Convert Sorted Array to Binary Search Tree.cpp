class Solution {
public:
    
    TreeNode* helper(vector<int>&nums,int l,int h){
        if(l>h)return NULL;
        int mid=(l+h)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,l,mid-1);
        root->right=helper(nums,mid+1,h);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())return NULL;
        TreeNode*head=helper(nums,0,nums.size()-1);
        return head;
    }
};