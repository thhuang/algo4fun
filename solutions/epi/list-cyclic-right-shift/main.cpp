#include <epi/generic_test.h>
#include <epi/list_node.h>

#include <memory>
using namespace std;

int GetNodeCount(shared_ptr<ListNode<int>> lst);

shared_ptr<ListNode<int>> CyclicallyRightShiftList(
    shared_ptr<ListNode<int>> lst, int k) {
    int length = GetNodeCount(lst);
    if (length == 0) return lst;

    int shift = k % length;
    if (shift == 0) return lst;

    auto p0 = lst;
    auto p1 = lst;
    for (int i = 0; i < shift; ++i) p1 = p1->next;
    while (p1->next) p0 = p0->next, p1 = p1->next;
    auto head = p0->next;
    p0->next = nullptr;
    p1->next = lst;

    return head;
}

int GetNodeCount(shared_ptr<ListNode<int>> lst) {
    int length = 0;
    while (lst) ++length, lst = lst->next;
    return length;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L", "k"};
    return GenericTestMain(args, "data.tsv", &CyclicallyRightShiftList,
                           DefaultComparator{}, param_names);
}
