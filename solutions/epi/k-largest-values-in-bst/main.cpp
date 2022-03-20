#include <epi/bst_node.h>
#include <epi/generic_test.h>

#include <memory>
#include <vector>
using namespace std;

vector<int> FindKLargestInBST(const unique_ptr<BstNode<int>>& tree, int k) {
    vector<int> result;

    function<void(const unique_ptr<BstNode<int>>&)> traverse =
        [&](const unique_ptr<BstNode<int>>& node) {
            if (!node) return;

            traverse(node->right);

            if (size(result) == k) return;
            result.emplace_back(node->data);

            traverse(node->left);
        };

    traverse(tree);
    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "k"};
    return GenericTestMain(args, "data.tsv", &FindKLargestInBST,
                           UnorderedComparator{}, param_names);
}
