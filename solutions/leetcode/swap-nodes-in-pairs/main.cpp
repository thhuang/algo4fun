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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* p = &dummy;
        while (p->next && p->next->next) {
            ListNode* p0 = p->next;
            ListNode* p1 = p->next->next;
            ListNode* p2 = p->next->next->next;
            p1->next = p0;
            p0->next = p2;
            p->next = p1;
            p = p0;
        }
        return dummy.next;
    }
};
