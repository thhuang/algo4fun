/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        auto p = head;
        while (p != slow) {
            slow = slow->next;
            p = p->next;
        }
        return p;
    }
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                auto result = head;
                while (result != slow) {
                    result = result->next;
                    slow = slow->next;
                }
                return result;
            }
        }
        return nullptr;
    }
};
