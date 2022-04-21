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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* p0 = &dummy;

        bool done = false;
        while (true) {
            ListNode* p3 = p0;
            for (int i = 0; i <= k; ++i) {
                if (p3) {
                    p3 = p3->next;
                } else {
                    done = true;
                }
            }
            if (done) break;

            ListNode* p1 = p0->next;
            for (int i = 0; i < k; ++i) {
                ListNode* p2 = p1->next;
                p1->next = p3;
                p3 = p1;
                p1 = p2;
            }
            p0->next = p3;

            for (int i = 0; i < k; ++i) p0 = p0->next;
        }

        return dummy.next;
    }
};
