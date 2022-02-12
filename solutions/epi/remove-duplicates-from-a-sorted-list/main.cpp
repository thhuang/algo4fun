#include <epi/generic_test.h>
#include <epi/list_node.h>

#include <memory>
using namespace std;

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L) {
    for (auto p = L; p; p = p->next) {
        while (p->next && p->next->data == p->data) {
            p->next = p->next->next;
        }
    }
    return L;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L"};
    return GenericTestMain(args, "data.tsv", &RemoveDuplicates,
                           DefaultComparator{}, param_names);
}
