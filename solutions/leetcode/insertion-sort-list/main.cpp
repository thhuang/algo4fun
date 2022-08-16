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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy;

        while (head) {
            ListNode* u = head;
            ListNode* p = &dummy;
            while (p->next != nullptr && p->next->val < u->val) p = p->next;

            head = head->next;
            u->next = p->next;
            p->next = u;
        }

        return dummy.next;
    }
};
