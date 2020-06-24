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
class Solution {
    
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode head(0);
        ListNode*headptr=&head;
        while(l1&&l2){
            if(l1->val<l2->val){
                headptr->next=l1;
                l1=l1->next;
            }else{
                headptr->next=l2;
                l2=l2->next;
            }
            headptr=headptr->next;
        }
        headptr->next=(!l2)?l1:l2;
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
    
    ListNode*mergesort(ListNode*head,ListNode*tail){
        if(head==tail)return head;
        ListNode*mid=getMid(head,tail);
        ListNode* sortpost=mergesort(mid->next,tail);
        mid->next=NULL;
        ListNode* sortpre=mergesort(head,mid);
        return merge(sortpre,sortpost);
    }
    
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*tail=head;
        while(tail->next)tail=tail->next;
        return mergesort(head,tail); 
    }
};