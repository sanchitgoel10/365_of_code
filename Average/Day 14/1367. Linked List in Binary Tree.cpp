/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(TreeNode*root,ListNode* node){
        if(node==NULL)return 1;
        if(root==NULL)return 0;
        if(root->val==node->val){
            return solve(root->left,node->next)||solve(root->right,node->next);
        }//yaha else condition lagane ka man karega tera but usse subsequence check hogi purapattern nhi
        return 0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)return false;  //ye kyu lagaya sochega tu but niche jab tu do call kar raha hai waha null pass ho sakta hai
        return solve(root,head)||isSubPath(head,root->left)||isSubPath(head,root->right);
        //yaha dhyan se dekh ek solve ka call hai do issubpath hi hai
    }
};