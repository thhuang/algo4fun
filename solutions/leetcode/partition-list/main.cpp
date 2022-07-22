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
        auto pl = &l;
        auto pr = &r;
        auto p = head;
        while (p) {
            if (p->val < x) {
                pl->next = p;
                pl = pl->next;
            } else {  // p->val >= x
                pr->next = p;
                pr = pr->next;
            }
            p = p->next;
        }
        pl->next = r.next;
        pr->next = nullptr;
        return l.next;
    }
};
