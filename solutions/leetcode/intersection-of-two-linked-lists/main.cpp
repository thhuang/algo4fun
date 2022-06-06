/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode *p) {
        if (!p) return 0;
        int count = 0;
        while (p) p = p->next, ++count;
        return count;
    }

    ListNode *moveForward(ListNode *p, int steps) {
        for (int i = 0; i < steps; ++i) p = p->next;
        return p;
    }

    ListNode *findIntersection(ListNode *pa, ListNode *pb) {
        while (pa && pb && pa != pb) pa = pa->next, pb = pb->next;
        return pa;
    }

   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = length(headA), lb = length(headB);

        if (la == -1 || lb == -1) return nullptr;

        ListNode *pa = headA, *pb = headB;
        if (la > lb) {
            pa = moveForward(pa, la - lb);
        } else {  // la <= lb
            pb = moveForward(pb, lb - la);
        }

        return findIntersection(pa, pb);
    }
};
