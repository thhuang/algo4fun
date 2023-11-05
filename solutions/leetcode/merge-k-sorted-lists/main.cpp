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
        for (ListNode* u : lists) {
            if (u == nullptr) continue;
            pq.push(u);
        }

        ListNode dummy;
        ListNode* p = &dummy;

        while (!pq.empty()) {
            ListNode* u = pq.top();
            pq.pop();

            p = p->next = u;

            if (u->next == nullptr) continue;

            pq.push(u->next);
        }

        return dummy.next;
    }
};
