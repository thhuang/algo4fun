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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (auto a = headA; a; a = a->next) {
            a->val = -a->val;
        }

        ListNode *result;
        for (auto b = headB; b; b = b->next) {
            if (b->val < 0) {
                result = b;
                break;
            }
        }

        for (auto a = headA; a; a = a->next) {
            a->val = -a->val;
        }

        return result;
    }
};

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

        ListNode *pa = headA, *pb = headB;
        if (la > lb) {
            pa = moveForward(pa, la - lb);
        } else {  // la <= lb
            pb = moveForward(pb, lb - la);
        }

        return findIntersection(pa, pb);
    }
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        for (auto a = headA; a; a = a->next) ++lenA;

        int lenB = 0;
        for (auto b = headB; b; b = b->next) ++lenB;

        auto a = headA;
        auto b = headB;
        if (lenA > lenB) {
            for (int i = lenB; i < lenA; ++i) a = a->next;
        } else {
            for (int i = lenA; i < lenB; ++i) b = b->next;
        }

        while (a) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }

        return nullptr;
    }
};
