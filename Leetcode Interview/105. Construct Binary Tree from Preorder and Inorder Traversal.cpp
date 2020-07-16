/*
he basic idea is here:
Say we have 2 arrays, PRE and IN.
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it :)
*/
class Solution {
public:
    
    TreeNode* helper(int prestart,int istart,int iend,vector<int>& pre,vector<int>& in){
        if(prestart>=pre.size()||istart>iend)return NULL;
        TreeNode* root= new TreeNode(pre[prestart]);
        int rootindex=0;
        for(int i=istart;i<=iend;i++){
            if(in[i]==root->val){
                rootindex=i;
                break;
            }
        }
        root->left=helper(prestart+1,istart,rootindex-1,pre,in);
        root->right=helper(prestart+rootindex-istart+1,rootindex+1,iend,pre,in);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
};