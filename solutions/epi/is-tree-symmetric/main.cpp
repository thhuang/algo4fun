#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
using namespace std;

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
    stack<BinaryTreeNode<int>*> dfsLeftStack;
    stack<BinaryTreeNode<int>*> dfsRightStack;
    dfsLeftStack.push(tree.get());
    dfsRightStack.push(tree.get());

    while (!dfsLeftStack.empty() || !dfsRightStack.empty()) {
        if (dfsLeftStack.empty() || dfsRightStack.empty()) return false;

        auto left = dfsLeftStack.top();
        auto right = dfsRightStack.top();
        dfsLeftStack.pop();
        dfsRightStack.pop();

        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->data != right->data) return false;

        dfsLeftStack.push(left->left.get());
        dfsLeftStack.push(left->right.get());
        dfsRightStack.push(right->right.get());
        dfsRightStack.push(right->left.get());
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &IsSymmetric, DefaultComparator{},
                           param_names);
}
