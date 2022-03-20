#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>

#include <limits>
#include <memory>
using namespace std;

/* bool IsInRange(const unique_ptr<BinaryTreeNode<int>>& node, int minimum, */
/*                int maximum) { */
/*     if (!node) return true; */
/*     if (node->data < minimum || node->data > maximum) return false; */
/*     return IsInRange(node->left, minimum, node->data) && */
/*            IsInRange(node->right, node->data, maximum); */
/* } */

/* bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) { */
/*     return IsInRange(tree, numeric_limits<int>::min(), */
/*                      numeric_limits<int>::max()); */
/* } */

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
    int curr_val = numeric_limits<int>::min();
    function<bool(const unique_ptr<BinaryTreeNode<int>>&)> traverse =
        [&](const unique_ptr<BinaryTreeNode<int>>& node) {
            if (!node) return true;

            if (!traverse(node->left)) return false;

            if (node->data < curr_val) return false;
            curr_val = node->data;

            if (!traverse(node->right)) return false;

            return true;
        };
    return traverse(tree);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &IsBinaryTreeBST,
                           DefaultComparator{}, param_names);
}
