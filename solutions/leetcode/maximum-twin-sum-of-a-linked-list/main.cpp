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
    int pairSum(ListNode* head) {
        ListNode *p0 = nullptr, *p1 = head, *fast = head;

        while (fast) {
            fast = fast->next->next;

            ListNode* p2 = p1->next;
            p1->next = p0;
            p0 = p1;
            p1 = p2;
        }

        int result = 0;
        while (p0) {
            result = max(result, p0->val + p1->val);
            p0 = p0->next;
            p1 = p1->next;
        }

        return result;
    }
};
