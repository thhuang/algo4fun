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