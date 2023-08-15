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
    ListNode* partition(ListNode* head, int x) {
        ListNode left, right;
        ListNode* l = &left;
        ListNode* r = &right;
        while (head) {
            if (head->val < x) {
                l = l->next = head;
            } else {
                r = r->next = head;
            }
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};
