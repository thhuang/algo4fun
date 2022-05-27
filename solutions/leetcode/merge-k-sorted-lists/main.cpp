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
        auto comp = [&](ListNode* a, ListNode* b) -> bool {
            if (a == nullptr) return true;
            if (b == nullptr) return false;
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);
        for (ListNode* l : lists) {
            if (l) q.push(l);
        }

        ListNode dummy;
        auto p = &dummy;

        while (!q.empty()) {
            auto u = q.top();
            q.pop();

            p->next = u;
            p = p->next;

            u = u->next;
            if (u) q.push(u);
        }

        return dummy.next;
    }
};
