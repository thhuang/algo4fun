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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;

        bool done = false;
        while (true) {
            ListNode* p3 = p0;
            for (int i = 0; i <= k; ++i) {
                if (p3) {
                    p3 = p3->next;
                } else {
                    done = true;
                }
            }
            if (done) break;

            ListNode* p1 = p0->next;
            for (int i = 0; i < k; ++i) {
                ListNode* p2 = p1->next;
                p1->next = p3;
                p3 = p1;
                p1 = p2;
            }
            p0->next = p3;

            for (int i = 0; i < k; ++i) p0 = p0->next;
        }

        return dummy.next;
    }
};

class Solution {
    ListNode* forward(ListNode* u, int k) {
        for (int i = 0; u && i < k; ++i) u = u->next;
        return u;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode *p0 = nullptr, *p1 = head;
        while (p1) {
            ListNode* p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }
        return {p0, head};
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);

        for (ListNode *p = &dummy, *q = forward(p, k); q != nullptr;
             p = q, q = forward(p, k)) {
            ListNode* c = q->next;
            q->next = nullptr;

            tie(p->next, q) = reverse(p->next);
            q->next = c;
        }

        return dummy.next;
    }
};
