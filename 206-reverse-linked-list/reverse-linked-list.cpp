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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* p = nullptr;
        ListNode* q = head->next;
        
        while(head != nullptr) {
            head->next = p;
            p = head;
            head= q;
            if(q != nullptr) q=q->next;
        }

        return p;
    }
};

/* 
 * q = 2;
 * head->next -> nullptr
 * p = 1;
 * head = 2;
 */