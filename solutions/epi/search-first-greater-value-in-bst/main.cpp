#include <epi/bst_node.h>
#include <epi/generic_test.h>

#include <memory>
using namespace std;

BstNode<int>* FindFirstGreaterThanK(const unique_ptr<BstNode<int>>& tree,
                                    int k) {
    BstNode<int>* node = tree.get();
    BstNode<int>* result = nullptr;
    while (node) {
        if (node->data <= k) {
            node = node->right.get();
            continue;
        }
        result = node;
        node = node->left.get();
    }
    return result;
}

int FindFirstGreaterThanKWrapper(const unique_ptr<BstNode<int>>& tree, int k) {
    auto result = FindFirstGreaterThanK(tree, k);
    return result ? result->data : -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "k"};
    return GenericTestMain(args, "data.tsv", &FindFirstGreaterThanKWrapper,
                           DefaultComparator{}, param_names);
}
