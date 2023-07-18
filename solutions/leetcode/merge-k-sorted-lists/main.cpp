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
        auto cmp = [&](ListNode* b, ListNode* a) -> bool {
            return a->val < b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto l : lists) {
            if (l) pq.push(l);
        }

        ListNode dummy;
        auto p = &dummy;

        while (!pq.empty()) {
            auto l = pq.top();
            pq.pop();

            p = p->next = l;
            l = l->next;

            if (l) pq.push(l);
        }

        return dummy.next;
    }
};
