#include <epi/binary_tree_with_parent_prototype.h>
#include <epi/generic_test.h>

#include <memory>
using namespace std;

BinaryTreeNode<int>* GetNextNode(BinaryTreeNode<int>* node);

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (!tree) return {};

    auto iter = tree.get();
    while (iter->left) iter = iter->left.get();

    vector<int> result;
    while (iter) {
        result.push_back(iter->data);
        iter = GetNextNode(iter);
    }

    return result;
}

BinaryTreeNode<int>* GetNextNode(BinaryTreeNode<int>* node) {
    if (node->right) {
        node = node->right.get();
        while (node->left) node = node->left.get();
        return node;
    }

    while (node->parent) {
        if (node->parent->left.get() == node) return node->parent;
        node = node->parent;
    }

    return nullptr;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &InorderTraversal,
                           DefaultComparator{}, param_names);
}
