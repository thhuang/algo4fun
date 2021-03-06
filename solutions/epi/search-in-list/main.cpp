#include <epi/generic_test.h>
#include <epi/list_node.h>

#include <memory>
using namespace std;

shared_ptr<ListNode<int>> SearchList(shared_ptr<ListNode<int>> L, int key) {
    while (L && L->data != key) L = L->next;
    return L;
}
int SearchListWrapper(shared_ptr<ListNode<int>> L, int key) {
    auto result = SearchList(L, key);
    return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"L", "key"};
    return GenericTestMain(args, "data.tsv", &SearchListWrapper,
                           DefaultComparator{}, param_names);
}
