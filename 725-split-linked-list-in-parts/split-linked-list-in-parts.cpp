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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;
        int totalLength = 0;

        while (curr) {
            totalLength++;
            curr = curr->next;
        }

        int partSize = totalLength / k;
        int extraNodes = totalLength % k;

        curr = head;
        for (int i = 0; i < k && curr; ++i) {
            result[i] = curr;
            int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            for (int j = 1; j < currentPartSize; ++j) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};