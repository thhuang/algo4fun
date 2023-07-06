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
    ListNode* partition(ListNode* head, int x) {
        ListNode l, r;
        ListNode* a = &l;
        ListNode* b = &r;
        while (head) {
            if (head->val < x) {
                a = a->next = head;
            } else {
                b = b->next = head;
            }
            head = head->next;
        }
        a->next = r.next;
        b->next = nullptr;
        return l.next;
    }
};
