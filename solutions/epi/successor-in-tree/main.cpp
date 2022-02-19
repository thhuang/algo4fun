#include <epi/binary_tree_utils.h>
#include <epi/binary_tree_with_parent_prototype.h>
#include <epi/generic_test.h>
using namespace std;

BinaryTreeNode<int>* FindSuccessor(
    const unique_ptr<BinaryTreeNode<int>>& node) {
    auto iter = node.get();

    if (iter->right) {
        iter = iter->right.get();
        while (iter->left) iter = iter->left.get();
        return iter;
    }

    while (iter->parent) {
        if (iter->parent->left.get() == iter) return iter->parent;
        iter = iter->parent;
    }

    return nullptr;
}

int FindSuccessorWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                         int node_idx) {
    auto result = FindSuccessor(MustFindNode(tree, node_idx));
    return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "node_idx"};
    return GenericTestMain(args, "data.tsv", &FindSuccessorWrapper,
                           DefaultComparator{}, param_names);
}
