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
    int n;
    ListNode* head;

   public:
    Solution(ListNode* head) : head(head), n(0) {
        auto p = head;
        while (p) ++n, p = p->next;
    }

    int getRandom() {
        int r = rand();
        while (r <= INT_MAX % n) r = rand();

        auto p = head;
        int step = r % n;
        while (step--) p = p->next;

        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
