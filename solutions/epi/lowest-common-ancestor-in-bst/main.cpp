#include <epi/binary_tree_utils.h>
#include <epi/bst_node.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <memory>
using namespace std;

// Input nodes are nonempty and the key at s is less than or equal to that at b.
BstNode<int>* FindLca(const unique_ptr<BstNode<int>>& tree,
                      const unique_ptr<BstNode<int>>& s,
                      const unique_ptr<BstNode<int>>& b) {
    int small = s->data;
    int big = b->data;
    BstNode<int>* node = tree.get();

    while (node) {
        if (node->data < small) {
            node = node->right.get();
            continue;
        }

        if (node->data > big) {
            node = node->left.get();
            continue;
        }

        return node;
    }

    return nullptr;
}
int LcaWrapper(TimedExecutor& executor, const unique_ptr<BstNode<int>>& tree,
               int key0, int key1) {
    const unique_ptr<BstNode<int>>& node0 = MustFindNode(tree, key0);
    const unique_ptr<BstNode<int>>& node1 = MustFindNode(tree, key1);

    auto result = executor.Run([&] { return FindLca(tree, node0, node1); });

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
