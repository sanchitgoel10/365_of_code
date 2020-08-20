class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)return;
        ListNode*pre=NULL,*p=head;
        while(p->next){
            pre=p;
            p=p->next;
        }
        pre->next=NULL;    //detaching from previous node
        ListNode*next=head->next;
        reorderList(next);
        head->next=p;
        p->next=next;
    }
};