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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* p = &dummy;

        auto select1 = [&]() -> void {
            p = p->next = list1;
            list1 = list1->next;
        };

        auto select2 = [&]() -> void {
            p = p->next = list2;
            list2 = list2->next;
        };

        while (list1 || list2) {
            if (!list1) {
                select2();
            } else if (!list2) {
                select1();
            } else if (list1->val < list2->val) {
                select1();
            } else {
                select2();
            }
        }

        return dummy.next;
    }
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode();
        auto p = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }
        }
        p->next = list1 ? list1 : list2;

        return dummy->next;
    }
};
