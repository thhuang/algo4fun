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
    ListNode* reverse(ListNode* head) {
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        while (p1) {
            auto p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }
        return p0;
    }

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode dummy(0);
        auto p = &dummy;
        auto p1 = l1;
        auto p2 = l2;
        int v = 0;
        while (l1 || l2 || v) {
            p->next = new ListNode(v);
            p = p->next;
            v = 0;

            if (l1) p->val += l1->val, l1 = l1->next;
            if (l2) p->val += l2->val, l2 = l2->next;

            v = p->val / 10;
            p->val %= 10;
        }

        reverse(l1);
        reverse(l2);
        return reverse(dummy.next);
    }
};
