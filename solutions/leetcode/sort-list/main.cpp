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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* h0 = head;
        ListNode* h1 = slow->next;
        slow->next = nullptr;

        ListNode* p = &dummy;
        p->next = nullptr;

        ListNode* p0 = sortList(h0);
        ListNode* p1 = sortList(h1);

        while (p0 && p1) {
            if (p0->val < p1->val) {
                p->next = p0;
                p0 = p0->next;
            } else {  // p0->val >= p1->val
                p->next = p1;
                p1 = p1->next;
            }

            p = p->next;
        }

        p->next = p0 ? p0 : p1;

        return dummy.next;
    }
};
