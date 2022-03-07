#include <epi/generic_test.h>
#include <epi/list_node.h>

#include <memory>
using namespace std;

shared_ptr<ListNode<int>> Merge(shared_ptr<ListNode<int>>,
                                shared_ptr<ListNode<int>>);

shared_ptr<ListNode<int>> StableSortList(shared_ptr<ListNode<int>> L) {
    if (L == nullptr || L->next == nullptr) return L;

    auto slow = L;
    auto fast = L;
    auto pre_slow = slow;
    while (fast && fast->next) {
        pre_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre_slow->next = nullptr;

    auto left = StableSortList(L);
    auto right = StableSortList(slow);

    return Merge(left, right);
}

shared_ptr<ListNode<int>> Merge(shared_ptr<ListNode<int>> l0,
                                shared_ptr<ListNode<int>> l1) {
    auto dummy = make_shared<ListNode<int>>();
    auto p = dummy;
    while (l0 && l1) {
        if (l0->data < l1->data) {
            p->next = l0, l0 = l0->next;
        } else {
            p->next = l1, l1 = l1->next;
        }
        p = p->next;
    }

    p->next = l0 ? l0 : l1;
    return dummy->next;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L"};
    return GenericTestMain(args, "data.tsv", &StableSortList,
                           DefaultComparator{}, param_names);
}
