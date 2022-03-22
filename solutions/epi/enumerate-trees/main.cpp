#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <memory>
#include <stack>
#include <vector>
using namespace std;

unique_ptr<BinaryTreeNode<int>> Clone(unique_ptr<BinaryTreeNode<int>>& tree) {
    return !tree ? nullptr
                 : make_unique<BinaryTreeNode<int>>(
                       tree->data, Clone(tree->left), Clone(tree->right));
}

vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees(int num_nodes) {
    if (num_nodes == 0) return vector<unique_ptr<BinaryTreeNode<int>>>(1);

    vector<unique_ptr<BinaryTreeNode<int>>> result;
    for (int l = 0; l < num_nodes; ++l) {
        int r = num_nodes - 1 - l;

        auto left_subtrees = GenerateAllBinaryTrees(l);
        auto right_subtrees = GenerateAllBinaryTrees(r);

        for (auto& left : left_subtrees) {
            for (auto& right : right_subtrees) {
                result.emplace_back(make_unique<BinaryTreeNode<int>>(
                    0, Clone(left), Clone(right)));
            }
        }
    }

    return result;
}

vector<int> SerializeStructure(const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<int> result;

    stack<BinaryTreeNode<int>*> stack;
    stack.push(tree.get());
    while (!stack.empty()) {
        auto p = stack.top();
        stack.pop();
        result.push_back(p != nullptr);
        if (p) {
            stack.push(p->left.get());
            stack.push(p->right.get());
        }
    }
    return result;
}

vector<vector<int>> GenerateAllBinaryTreesWrapper(TimedExecutor& executor,
                                                  int num_nodes) {
    auto result =
        executor.Run([&] { return GenerateAllBinaryTrees(num_nodes); });

    vector<vector<int>> serialized;
    for (auto& x : result) {
        serialized.push_back(SerializeStructure(x));
    }
    sort(begin(serialized), end(serialized));
    return serialized;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "num_nodes"};
    return GenericTestMain(args, "data.tsv", &GenerateAllBinaryTreesWrapper,
                           DefaultComparator{}, param_names);
}
