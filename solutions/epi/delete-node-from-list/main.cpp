#include <epi/generic_test.h>
#include <epi/list_node.h>
#include <epi/timed_executor.h>
using namespace std;

// Assumes node_to_delete is not tail.
void DeletionFromList(const shared_ptr<ListNode<int>>& node_to_delete) {
    node_to_delete->data = node_to_delete->next->data;
    node_to_delete->next = node_to_delete->next->next;
}

shared_ptr<ListNode<int>> DeletionFromListWrapper(
    TimedExecutor& executor, const shared_ptr<ListNode<int>>& head,
    int node_to_delete_idx) {
    shared_ptr<ListNode<int>> selected_node = head;
    while (node_to_delete_idx-- > 0) {
        if (!selected_node || !selected_node->next)
            throw runtime_error("Node index is out of range");
        selected_node = selected_node->next;
    }

    executor.Run([&] { DeletionFromList(selected_node); });
    return head;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "head", "node_to_delete_idx"};
    return GenericTestMain(args, "data.tsv", &DeletionFromListWrapper,
                           DefaultComparator{}, param_names);
}
