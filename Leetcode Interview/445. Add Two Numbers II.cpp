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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        while(l1) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        }

        int m = nums1.size(), n = nums2.size();
        int sum = 0, carry = 0;

        ListNode *head = nullptr, *p = nullptr;

        for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) { //carry>0 wali condition hai imp
            sum = carry;
            if(i >= 0)              
                sum += nums1[i];

            if(j >= 0)
                sum += nums2[j];

            carry = sum / 10;

            p = new ListNode(sum%10);
            p->next = head;              
            head = p;              //head ko last se piche laate jaare hai
        }

        return head;
    }
};
//same but with stack
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        stack<int> s1, s2;
        while (h1) {
            s1.push(h1->val);
            h1 = h1->next;
        }
        while (h2) {
            s2.push(h2->val);
            h2 = h2->next;
        }
        int carry_on = 0;
        ListNode *curr = NULL, *prev = NULL;
        while (s1.size() || s2.size() || carry_on) {
            int sum = carry_on;
            if (s1.size()) {
                sum += s1.top();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.top();
                s2.pop();
            }
            carry_on = sum / 10;
            prev = new ListNode(sum % 10);
            prev->next = curr;
            curr = prev;
        }
        return curr;
    }
};