#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

// Delete the node past this one. Assume node is not a tail.
void DeleteAfter(const shared_ptr<ListNode<int>>& node) {
    node->next = node->next->next;
}

shared_ptr<ListNode<int>> DeleteFromListWrapper(
    TimedExecutor& executor, const shared_ptr<ListNode<int>>& head,
    int node_idx) {
    shared_ptr<ListNode<int>> selected_node = head;
    shared_ptr<ListNode<int>> prev;
    while (node_idx-- > 0) {
        if (!selected_node || !selected_node->next)
            throw runtime_error("Node index is out of range");
        prev = selected_node;
        selected_node = selected_node->next;
    }
    executor.Run([&] { DeleteAfter(prev); });
    return head;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "head", "node_idx"};
    return GenericTestMain(args, "data.tsv", &DeleteFromListWrapper,
                           DefaultComparator{}, param_names);
}
