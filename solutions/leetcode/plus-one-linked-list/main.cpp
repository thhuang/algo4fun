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
    ListNode* reverse(ListNode* head) {
        ListNode* p0 = nullptr;
        ListNode* p1 = head;
        while (p1) {
            auto p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }
        return p0;
    }

   public:
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* p = head;
        while (true) {
            ++p->val;
            if (p->val < 10) break;

            p->val = 0;

            if (p->next == nullptr) p->next = new ListNode(0);
            p = p->next;
        }
        return reverse(head);
    }
};

class Solution {
   public:
    ListNode* plusOne(ListNode* head) {
        auto leading = new ListNode(0, head);
        auto p = leading;
        auto right_most_not_nine = p;

        while (p) {
            if (p->val != 9) right_most_not_nine = p;
            p = p->next;
        }

        ++right_most_not_nine->val;

        p = right_most_not_nine->next;
        while (p) {
            p->val = 0;
            p = p->next;
        }

        if (leading->val != 0) {
            head = leading;
        } else {
            delete leading;
        }

        return head;
    }
};
