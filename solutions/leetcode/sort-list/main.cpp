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
        if (head == nullptr || head->next == nullptr) return head;

        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto l = head;
        auto r = slow->next;
        slow->next = nullptr;

        l = sortList(l);
        r = sortList(r);

        ListNode dummy;
        auto p = &dummy;
        while (l && r) {
            if (l->val < r->val) {
                p = p->next = l, l = l->next;
            } else {
                p = p->next = r, r = r->next;
            }
        }

        p->next = l ? l : r;

        return dummy.next;
    }
};
