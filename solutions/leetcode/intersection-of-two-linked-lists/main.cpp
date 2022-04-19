/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    int getNumNodes(ListNode* head) {
        ListNode dummy;
        auto p = &dummy;
        p->next = head;

        int count = 0;
        while (p->next) p = p->next, ++count;
        return count;
    }

    ListNode* getNthNode(ListNode* head, int n) {
        auto p = head;
        while (n--) p = p->next;
        return p;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int n0 = getNumNodes(headA);
        int n1 = getNumNodes(headB);

        auto p0 = headA;
        auto p1 = headB;
        if (n0 > n1) {
            p0 = getNthNode(headA, n0 - n1);
        } else {  // n0 <= n1
            p1 = getNthNode(headB, n1 - n0);
        }

        while (p0 && p1) {
            if (p0 == p1) return p0;
            p0 = p0->next;
            p1 = p1->next;
        }
        return nullptr;
    }
};
