#include <epi/generic_test.h>
#include <epi/list_node.h>
using namespace std;

shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
    if (!L || !L->next) return L;

    auto even = make_shared<ListNode<int>>();
    auto odd = make_shared<ListNode<int>>();
    auto odd_head = L->next;

    auto p = L;
    for (int i = 0; p; ++i) {
        auto& curr = i & 1 ? odd : even;
        curr->next = p;
        curr = curr->next;
        p = p->next;
    }
    even->next = odd_head;
    odd->next = nullptr;

    return L;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L"};
    return GenericTestMain(args, "data.tsv", &EvenOddMerge, DefaultComparator{},
                           param_names);
}
