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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        auto p = head;
        while (p) {
            ans <<= 1;
            ans += p->val;
            p = p->next;
        }
        return ans;
    }
};
