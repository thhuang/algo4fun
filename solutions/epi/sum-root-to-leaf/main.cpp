#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
using namespace std;

int Sum(BinaryTreeNode<int>* tree, int currVal);

int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
    return Sum(tree.get(), 0);
}

int Sum(BinaryTreeNode<int>* tree, int currVal) {
    if (!tree) return 0;

    int val = (currVal << 1) | tree->data;

    if (!tree->left && !tree->right) return val;

    return Sum(tree->left.get(), val) + Sum(tree->right.get(), val);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &SumRootToLeaf,
                           DefaultComparator{}, param_names);
}
