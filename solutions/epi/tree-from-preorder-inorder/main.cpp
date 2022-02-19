#include <epi/binary_tree_node.h>
#include <epi/binary_tree_utils.h>
#include <epi/generic_test.h>

#include <unordered_map>
using namespace std;

unique_ptr<BinaryTreeNode<int>> ConstructTree(
    const vector<int>& preorder, const vector<int>& inorder,
    const unordered_map<int, int>& inorder_index, int preorder_begin,
    int preorder_end, int inorder_begin, int inorder_end);

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder(
    const vector<int>& preorder, const vector<int>& inorder) {
    unordered_map<int, int> inorder_index;
    for (int i = 0; i < size(inorder); ++i) inorder_index[inorder[i]] = i;

    return ConstructTree(preorder, inorder, inorder_index, 0, size(preorder), 0,
                         size(inorder));
}

unique_ptr<BinaryTreeNode<int>> ConstructTree(
    const vector<int>& preorder, const vector<int>& inorder,
    const unordered_map<int, int>& inorder_index, int preorder_begin,
    int preorder_end, int inorder_begin, int inorder_end) {
    if (preorder_begin == preorder_end) return nullptr;

    int data = preorder[preorder_begin];
    auto node = make_unique<BinaryTreeNode<int>>(data);

    int left_inorder_begin = inorder_begin;
    int left_inorder_end = inorder_index.at(data);
    int left_preorder_begin = preorder_begin + 1;
    int left_preorder_end =
        left_preorder_begin + left_inorder_end - left_inorder_begin;

    int right_inorder_begin = inorder_index.at(data) + 1;
    int right_inorder_end = inorder_end;
    int right_preorder_begin = left_preorder_end;
    int right_preorder_end = preorder_end;

    node->left =
        ConstructTree(preorder, inorder, inorder_index, left_preorder_begin,
                      left_preorder_end, left_inorder_begin, left_inorder_end);

    node->right = ConstructTree(preorder, inorder, inorder_index,
                                right_preorder_begin, right_preorder_end,
                                right_inorder_begin, right_inorder_end);

    return node;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"preorder", "inorder"};
    return GenericTestMain(args, "data.tsv", &BinaryTreeFromPreorderInorder,
                           DefaultComparator{}, param_names);
}
