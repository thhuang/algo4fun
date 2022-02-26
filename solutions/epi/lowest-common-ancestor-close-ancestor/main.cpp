#include <epi/binary_tree_utils.h>
#include <epi/binary_tree_with_parent_prototype.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
    unordered_set<BinaryTreeNode<int>*> seen;
    auto p1 = node0.get();
    auto p2 = node1.get();
    while (p1 || p2) {
        if (p1) {
            if (seen.insert(p1).second == false) return p1;
            p1 = p1->parent;
        }
        if (p2) {
            if (seen.insert(p2).second == false) return p2;
            p2 = p2->parent;
        }
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
