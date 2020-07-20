class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pseudo_head(0);
        pseudo_head.next = head;
        ListNode *prev = &pseudo_head;
        ListNode *cur = head;
        while(cur){
            if(cur->val == val)   prev->next = cur->next;
            else    prev = prev->next;
            cur = cur->next;
        }
        return pseudo_head.next;
    }
};


//recursive
ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) return NULL;
    if (val == head->val) return removeElements(head->next,val);
    head->next = removeElements(head->next,val);
    return head;
}