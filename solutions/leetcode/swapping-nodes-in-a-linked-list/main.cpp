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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0, head);

        auto p = &dummy;
        for (int i = 0; i < k; ++i) p = p->next;
        auto a = p;

        int n = k;
        while (p->next) p = p->next, ++n;

        p = &dummy;
        for (int i = 0; i < n - k + 1; ++i) p = p->next;
        auto b = p;

        swap(a->val, b->val);

        return dummy.next;
    }
};
