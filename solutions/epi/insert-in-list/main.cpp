#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

// Insert new_node after node.
void InsertAfter(const shared_ptr<ListNode<int>>& node,
                 const shared_ptr<ListNode<int>>& new_node) {
    new_node->next = node->next;
    node->next = new_node;
}

shared_ptr<ListNode<int>> InsertListWrapper(TimedExecutor& executor,
                                            const shared_ptr<ListNode<int>>& l,
                                            int node_idx, int new_node_data) {
    auto node = l;
    while (node_idx > 1) {
        node = node->next;
        --node_idx;
    }
    auto new_node = make_shared<ListNode<int>>(new_node_data, nullptr);

    executor.Run([&] { InsertAfter(node, new_node); });

    return l;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "l", "node_idx", "new_node_data"};
    return GenericTestMain(args, "data.tsv", &InsertListWrapper,
                           DefaultComparator{}, param_names);
}
