#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

vector<const unique_ptr<BinaryTreeNode<int>>*> CreateListOfLeaves(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (!tree) return {};

    stack<const unique_ptr<BinaryTreeNode<int>>*> st;
    st.emplace(&tree);
    vector<const unique_ptr<BinaryTreeNode<int>>*> result;

    while (!st.empty()) {
        auto& node = *st.top();
        st.pop();

        if (!node->left && !node->right) {
            result.emplace_back(&node);
            continue;
        }

        if (node->right) st.emplace(&node->right);
        if (node->left) st.emplace(&node->left);
    }

    return result;
}
vector<int> CreateListOfLeavesWrapper(
    TimedExecutor& executor, const unique_ptr<BinaryTreeNode<int>>& tree) {
    auto result = executor.Run([&] { return CreateListOfLeaves(tree); });

    if (any_of(begin(result), end(result),
               [](const unique_ptr<BinaryTreeNode<int>>*& x) {
                   return !x || !*x;
               })) {
        throw TestFailure("Result list can't contain nullptr");
    }

    vector<int> extracted_result;
    for (const auto& x : result) {
        extracted_result.push_back(x->get()->data);
    }
    return extracted_result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "tree"};
    return GenericTestMain(args, "data.tsv", &CreateListOfLeavesWrapper,
                           DefaultComparator{}, param_names);
}
