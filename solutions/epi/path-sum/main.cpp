#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
using namespace std;

bool HasPathSum(const unique_ptr<BinaryTreeNode<int>>& tree,
                int remaining_weight) {
    if (tree == nullptr) return false;

    remaining_weight -= tree->data;

    if (!tree->left && !tree->right) return remaining_weight == 0;

    return HasPathSum(tree->left, remaining_weight) ||
           HasPathSum(tree->right, remaining_weight);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "remaining_weight"};
    return GenericTestMain(args, "data.tsv", &HasPathSum, DefaultComparator{},
                           param_names);
}
