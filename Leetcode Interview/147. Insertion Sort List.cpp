//Recursive
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == NULL)
            return head;
        ListNode *h = insertionSortList(head->next);
        if (head->val <= h->val) {  // first case
            head->next = h;
            return head;
        }
        ListNode *node = h;   // second case
        while (node->next && head->val > node->next->val)
            node = node->next;
        head->next = node->next;
        node->next = head;
        return h;
    }
};
//Iterative
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        ListNode *cur, *next;
        while(head) {
            cur = &dummy;
            next = head->next;
            while(cur->next && cur->next->val < head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = next;
        }
        return dummy.next;
    }
};