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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(0, head);
        auto p = dummy;
        while (p && p->next) {
            if (p->next->val != val) {
                p = p->next;
            } else {
                p->next = p->next->next;
            }
        }
        return dummy->next;
    }
};
