#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
using namespace std;

struct IsBalancedInfo {
    bool isBalanced;
    int height;
};

IsBalancedInfo CheckIsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (!tree) return IsBalancedInfo{true, 0};

    auto left = CheckIsBalanced(tree->left);
    auto right = CheckIsBalanced(tree->right);
    return IsBalancedInfo{
        left.isBalanced && right.isBalanced &&
            abs(left.height - right.height) <= 1,
        max(left.height, right.height) + 1,
    };
}

bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    auto res = CheckIsBalanced(tree);

    return res.isBalanced;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &IsBalanced, DefaultComparator{},
                           param_names);
}
