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
    ListNode* reverse(ListNode* head) {
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        while (p1) {
            ListNode* p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }
        return p0;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p0 = head;
        ListNode* p1 = slow->next;
        slow->next = nullptr;

        p1 = reverse(p1);

        ListNode d;
        ListNode* p = &d;
        while (true) {
            if (!p0) break;
            p->next = p0, p0 = p0->next, p = p->next;

            if (!p1) break;
            p->next = p1, p1 = p1->next, p = p->next;
        }
    }
};
