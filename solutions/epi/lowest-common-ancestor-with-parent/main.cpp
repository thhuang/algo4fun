#include <epi/binary_tree_utils.h>
#include <epi/binary_tree_with_parent_prototype.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

int GetDepth(BinaryTreeNode<int>* node) {
    int depth = 0;
    while (node) ++depth, node = node->parent;
    return depth;
}

BinaryTreeNode<int>* Advance(BinaryTreeNode<int>* node, int steps) {
    while (steps--) node = node->parent;
    return node;
}

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    auto n0 = node0.get();
    auto n1 = node1.get();

    int d0 = GetDepth(n0);
    int d1 = GetDepth(n1);
    if (d0 > d1) {
        n0 = Advance(n0, d0 - d1);
    } else {
        n1 = Advance(n1, d1 - d0);
    }

    while (n0 && n1) {
        if (n0 == n1) return n0;
        n0 = n0->parent;
        n1 = n1->parent;
    }

    return nullptr;
}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
    const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
    const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

    auto result = executor.Run([&] { return Lca(node0, node1); });

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
