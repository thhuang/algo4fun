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
    }

   public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode pos, neg;

        ListNode* p = &pos;
        ListNode* n = &neg;

        while (head) {
            if (head->val >= 0) {
                p = p->next = head;
            } else {
                n = n->next = head;
            }
            head = head->next;
        }

        p->next = nullptr;
        n->next = nullptr;

        if (n == &neg) return pos.next;

        n = neg.next;
        neg.next = reverse(neg.next);
        n->next = pos.next;

        return neg.next;
    }
};
