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

    int length(ListNode* head) {
        int result = 0;
        while (head) ++result, head = head->next;
        return result;
    }

    ListNode* forward(ListNode* u, int k) {
        for (int i = 0; i < k; ++i) u = u->next;
        return u;
    }

   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n = length(head);
        k %= n;
        head = reverse(head);

        ListNode dummy(0, head);

        auto p0 = &dummy;
        auto p1 = forward(&dummy, k);

        auto p2 = reverse(p1->next);
        p1->next = nullptr;

        p0->next = reverse(p0->next);
        p1 = forward(p0, k);
        p1->next = p2;

        return dummy.next;
    }
};

class Solution {
    ListNode* reverse(ListNode* head, int k) {
        ListNode* a = nullptr;
        ListNode* b = head;
        for (int i = 0; i < k; ++i) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }

   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        ListNode* p = head;
        int n = 0;
        while (p) p = p->next, ++n;

        k %= n;
        if (k == 0) return head;

        ListNode dummy(0, head);
        ListNode* a = &dummy;
        a->next = reverse(a->next, n);

        ListNode* b = a->next;
        for (int i = 0; i < k; ++i) b = b->next;

        ListNode* c = a->next;
        a->next = reverse(a->next, k);
        c->next = reverse(b, n - k);

        return a->next;
    }
};
