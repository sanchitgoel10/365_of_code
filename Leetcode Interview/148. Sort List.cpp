class Solution {
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* headPtr = &head; 
        while(l1 && l2) {
            if(l1->val < l2->val) {
                headPtr->next = l1;
                l1 = l1->next;
            } else {
                headPtr->next = l2;
                l2 = l2->next;
            }
            headPtr = headPtr->next;
        }
        headPtr->next = (!l1 )? l2 : l1;
        return head.next;
    }
    
    ListNode* getMid(ListNode* front, ListNode* back) {
        if(front == back) return front;
        ListNode* slow = front;
        ListNode* fast = front;
        while(slow && fast && fast->next && fast->next->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeSortList(ListNode* head, ListNode* tail) {
        if(head == tail) return head;
        ListNode* mid = getMid(head, tail);
        ListNode* sortedPost = mergeSortList(mid->next, tail);
        mid->next = NULL;
        ListNode* sortedPre = mergeSortList(head, mid);
        
        return mergeList(sortedPre, sortedPost);
    }
    
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
        }
        return mergeSortList(head, tail);
    }
};