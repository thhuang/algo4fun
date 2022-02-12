#include <epi/generic_test.h>
#include <epi/list_node.h>

#include <memory>
using namespace std;

// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L,
                                        int k) {
    auto dummy = make_shared<ListNode<int>>(0, L);
    auto p0 = dummy;
    auto p1 = L;

    for (int i = 0; i < k; ++i) p1 = p1->next;
    while (p1) p0 = p0->next, p1 = p1->next;
    p0->next = p0->next->next;

    return dummy->next;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L", "k"};
    return GenericTestMain(args, "data.tsv", &RemoveKthLast,
                           DefaultComparator{}, param_names);
}
