#include <epi/generic_test.h>
#include <epi/list_node.h>
using namespace std;

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
    auto dummy = make_shared<ListNode<int>>();
    auto p = dummy;
    while (L1 && L2) {
        if (L1->data < L2->data) {
            p->next = L1;
            L1 = L1->next;
        } else {
            p->next = L2;
            L2 = L2->next;
        }
        p = p->next;
    }

    p->next = L1 ? L1 : L2;

    return dummy->next;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L1", "L2"};
    return GenericTestMain(args, "data.tsv", &MergeTwoSortedLists,
                           DefaultComparator{}, param_names);
}
