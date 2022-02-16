#include <epi/binary_tree_node.h>
#include <epi/binary_tree_utils.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

struct SearchRes {
    int num_target_nodes;
    BinaryTreeNode<int>* ancestor;
};

SearchRes SearchNode(const unique_ptr<BinaryTreeNode<int>>& root,
                     const unique_ptr<BinaryTreeNode<int>>& node0,
                     const unique_ptr<BinaryTreeNode<int>>& node1) {
    if (!root) return SearchRes{0, nullptr};
    if (root == node0 || root == node1) return SearchRes{1, root.get()};

    auto left_res = SearchNode(root->left, node0, node1);
    auto right_res = SearchNode(root->right, node0, node1);

    if (left_res.num_target_nodes == 1 && right_res.num_target_nodes == 1)
        return SearchRes{2, root.get()};

    if (left_res.ancestor || left_res.num_target_nodes == 1) return left_res;
    if (right_res.ancestor || left_res.num_target_nodes == 1) return right_res;

    return SearchRes{0, nullptr};
}

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& tree,
                         const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    return SearchNode(tree, node0, node1).ancestor;
}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
    const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
    const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

    auto result = executor.Run([&] { return Lca(tree, node0, node1); });

    if (!result) {
        throw TestFailure("Result can not be nullptr");
    }
    return result->data;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "tree", "key0", "key1"};
    return GenericTestMain(args, "data.tsv", &LcaWrapper, DefaultComparator{},
                           param_names);
}
