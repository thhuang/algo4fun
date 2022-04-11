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
        ListNode dummy(0, head);
        auto p = &dummy;
        while (p && p->next && p->next->next) {
            if (p->next->val != p->next->next->val) {
                p = p->next;
                continue;
            }

            int v = p->next->val;
            while (p->next && p->next->val == v) {
                p->next = p->next->next;
            }
        }
        return dummy.next;
    }
};
