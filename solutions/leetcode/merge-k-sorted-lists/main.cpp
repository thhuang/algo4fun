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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* b, ListNode* a) -> bool {
            return a->val < b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* lst : lists) {
            if (lst) pq.push(lst);
        }

        ListNode dummy;
        auto p = &dummy;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            p->next = new ListNode(u->val);
            p = p->next;

            u = u->next;
            if (u) pq.push(u);
        }

        return dummy.next;
    }
};
