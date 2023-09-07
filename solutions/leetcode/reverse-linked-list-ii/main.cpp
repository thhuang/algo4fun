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
    void reverse(ListNode* head) {
        ListNode* a = nullptr;
        ListNode* b = head;
        while (b) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);

        auto a = &dummy;
        for (int i = 1; i < left; ++i) a = a->next;

        auto b = a->next;

        auto c = &dummy;
        for (int i = 0; i < right; ++i) c = c->next;

        auto d = c->next;

        c->next = nullptr;
        reverse(b);

        a->next = c;
        b->next = d;

        return dummy.next;
    }
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);

        ListNode* a = &dummy;
        for (int i = 1; i < left; ++i) a = a->next;

        ListNode* b = a->next;
        ListNode* c = b->next;
        for (int i = left; i < right; ++i) {
            ListNode* d = c->next;
            c->next = a->next;
            a->next = c;
            c = d;
        }
        b->next = c;

        return dummy.next;
    }
};
