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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*ns=head;
        ListNode*nf=head;
        while(nf!=NULL&&nf->next!=NULL){
            ns=ns->next;
            nf=nf->next->next;
        }
        return ns;
    }
};