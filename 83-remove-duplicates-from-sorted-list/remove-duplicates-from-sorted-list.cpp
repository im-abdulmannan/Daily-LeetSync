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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* c = head;

        while(c->next != nullptr) {
            ListNode* d = c->next;
            
            if(c->val == d->val) {
                ListNode* t = d;
                c->next = d->next;
                delete t;
            } else {
                c = c->next;
            }
        }

        return head;
    }
};