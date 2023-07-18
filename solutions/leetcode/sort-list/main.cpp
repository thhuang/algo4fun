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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode *a, *b, *c;
        a = b = c = &dummy;

        while (c->next && c->next->next) {
            b = b->next;
            c = c->next->next;
        }

        auto l = a->next, r = b->next;
        b->next = nullptr;

        l = sortList(l);
        r = sortList(r);

        auto p = a;
        while (l && r) {
            if (l->val < r->val) {
                p = p->next = l;
                l = l->next;
            } else {
                p = p->next = r;
                r = r->next;
            }
        }

        p->next = l ? l : r;

        return dummy.next;
    }
};
