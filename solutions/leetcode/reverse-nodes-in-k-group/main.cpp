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
    void reverse(ListNode* head, int k) {
        ListNode* a = nullptr;
        ListNode* b = head;
        for (int i = 0; i < k; ++i) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
    }

   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);

        ListNode* a = &dummy;
        while (true) {
            ListNode* b = a;
            for (int i = 0; i < k && b != nullptr; ++i) b = b->next;
            if (b == nullptr) break;

            ListNode* c = a->next;
            ListNode* d = b->next;

            reverse(c, k);

            a->next = b;
            c->next = d;

            a = c;
        }

        return dummy.next;
    }
};

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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        auto a = &dummy;

        while (true) {
            auto b = a;
            for (int i = 0; i < k; ++i) {
                if (!b->next) return dummy.next;
                b = b->next;
            }
            auto c = a->next;
            auto d = b->next;

            b->next = nullptr;
            reverse(c);

            a->next = b;
            c->next = d;
            a = c;
        }

        return dummy.next;
    }
};
