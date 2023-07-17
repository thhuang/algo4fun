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

class Solution {
    ListNode* reverse(ListNode* u) {
        ListNode* a = nullptr;
        ListNode* b = u;
        while (b) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    };

   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode dummy;
        ListNode* p = &dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        while (p1 || p2 || carry) {
            if (p1) carry += p1->val, p1 = p1->next;
            if (p2) carry += p2->val, p2 = p2->next;
            p = p->next = new ListNode(carry % 10);
            carry /= 10;
        }

        reverse(l1);
        reverse(l2);

        return reverse(dummy.next);
    }
};
