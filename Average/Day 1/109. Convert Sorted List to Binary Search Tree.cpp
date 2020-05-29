class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            if(!head) return NULL;
            if(!head->next) return new TreeNode(head->val);
            
            // fast/slow pointer to find the midpoint
            auto slow = head;
            auto fast = head;
            auto pre = head;
            while(fast && fast->next) {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            pre->next = 0; // break two halves 
            
            // slow is the midpoint, use as root
            TreeNode* root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
            
            return root;
        }
    };