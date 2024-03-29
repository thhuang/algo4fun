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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd, even;
        ListNode *p = head, *o = &odd, *e = &even;
        for (int i = 1; p != nullptr; ++i) {
            if (i & 1) {
                o->next = p;
                p = p->next;
                o = o->next;
                o->next = nullptr;
            } else {
                e->next = p;
                p = p->next;
                e = e->next;
                e->next = nullptr;
            }
        }
        o->next = even.next;
        return odd.next;
    }
};

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd, even;
        ListNode *o = &odd, *e = &even;
        ListNode* p = o;
        for (int i = 1; head != nullptr; ++i, head = head->next) {
            p->next = head;
            i & 1 ? (o = o->next, p = e) : (e = e->next, p = o);
        }
        p->next = nullptr;
        o->next = even.next;
        return odd.next;
    }
};
