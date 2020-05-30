// recursively
ListNode* swapPairs1(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *res = head->next;
    head->next = swapPairs(res->next);
    res->next = head;
    return res;
}

// iteratively
ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0), *node;
    node = dummy;
    dummy->next = head;
    while (head && head->next) {
        ListNode *nxt = head->next;
        head->next = nxt->next;
        nxt->next = head;
        node->next = nxt;
        node = head;
        head = node->next;
    }
    return dummy->next;
}