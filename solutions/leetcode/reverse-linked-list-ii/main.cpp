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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);

        auto p0 = &dummy;
        for (int i = 1; i < left; ++i) p0 = p0->next;

        auto l = p0;
        auto r = p0->next;

        auto p1 = r;
        for (int i = 0; i < right - left + 1; ++i) {
            auto p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }

        l->next = p0;
        r->next = p1;

        return dummy.next;
    }
};
