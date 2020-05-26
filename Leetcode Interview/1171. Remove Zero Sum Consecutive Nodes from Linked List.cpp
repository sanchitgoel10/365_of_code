/*
Iterate for the first time,
calculate the prefix sum,
and save the it to seen[prefix]

Iterate for the second time,
calculate the prefix sum,
and directly skip to last occurrence of this prefix
*/
ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* i = dummy; i; i = i->next) {
            seen[prefix += i->val] = i;
        }
        prefix = 0;
        for (ListNode* i = dummy; i; i = i->next) {
            i->next = seen[prefix += i->val]->next;          //ye mat sochio ki map me vo value hogi ki nhi hogi hi jab pehele saari insert kari hai wahi wapis traverse hori hai worst case me usi elemnt ka next ayega 
        }
        return dummy->next;
    }