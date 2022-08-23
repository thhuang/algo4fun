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
    int len(ListNode* u) {
        int n = 0;
        while (u) ++n, u = u->next;
        return n;
    }

   public:
    bool isPalindrome(ListNode* head) {
        int n = len(head);

        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        for (int i = 0; i < n / 2; ++i) {
            ListNode* p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }

        if (n & 1) p1 = p1->next;

        while (p0 && p1) {
            if (p0->val != p1->val) return false;
            p0 = p0->next, p1 = p1->next;
        }

        return true;
    }
};
