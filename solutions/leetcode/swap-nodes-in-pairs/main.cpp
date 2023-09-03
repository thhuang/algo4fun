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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        auto p = &dummy;
        while (p->next && p->next->next) {
            auto a = p->next;
            auto b = a->next;
            auto c = b->next;
            p->next = b;
            b->next = a;
            a->next = c;
            p = a;
        }
        return dummy.next;
    }
};
