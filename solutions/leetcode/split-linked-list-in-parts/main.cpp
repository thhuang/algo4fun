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
    int len(ListNode* p) {
        int result = 0;
        while (p) p = p->next, ++result;
        return result;
    }

   public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = len(head);
        int base = n / k;
        int mod = n % k;

        vector<ListNode*> result;

        auto u = head;
        for (int i = 0; i < k; ++i) {
            ListNode dummy;
            auto p = &dummy;

            int m = base;
            if (i < mod) ++m;

            for (int j = 0; j < m; ++j) {
                p = p->next = u;
                tie(u, u->next) = pair<ListNode*, ListNode*>{u->next, nullptr};
            }

            result.push_back(dummy.next);
        }

        return result;
    }
};
