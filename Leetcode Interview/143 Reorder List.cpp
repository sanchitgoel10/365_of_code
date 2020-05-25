class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *p = head;
        ListNode *q = getMidNode(head);   
        q = reverseList(q);
        mergeList(p,q);
    } 
    
    ListNode* getMidNode(ListNode* head){
        ListNode *slow= head,*fast= head;
        while(slow && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;       //Kaat di list yaha se
        return mid;        
    }
    
    ListNode* reverseList(ListNode *root){
        ListNode* prev = NULL, *next = root, *curr = root;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        // returning head of reversed list
        //kyuki curr to while loop ke chakar me null ja chuka hoga
    }
    
    void mergeList(ListNode* p, ListNode* q){       //dry run karke dekhio
        ListNode* tmp;
        while(q){
            tmp = p->next;  // store address of next
            p->next = q;    // link to 2nd list
            q = q->next;    // increase 2nd list pointer
            p = p->next;    
            p->next = tmp;  // link to 1st list    //yaha tughe lagega direct p=temp kyu nhi kiya but usse link nhi hongi dono list
            p = p->next;    // increase 1st list pointer
        }
    }
};