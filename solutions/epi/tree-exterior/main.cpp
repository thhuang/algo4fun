#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

void LeftExterior(const unique_ptr<BinaryTreeNode<int>>& tree,
                  vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior);
void RightExterior(const unique_ptr<BinaryTreeNode<int>>& tree,
                   vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior);
void Leaves(const unique_ptr<BinaryTreeNode<int>>& tree,
            vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior);

vector<const unique_ptr<BinaryTreeNode<int>>*> ExteriorBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    if (!tree) return {};

    vector<const unique_ptr<BinaryTreeNode<int>>*> exterior{&tree};

    LeftExterior(tree->left, exterior);
    Leaves(tree->left, exterior);
    Leaves(tree->right, exterior);
    RightExterior(tree->right, exterior);

    return exterior;
}

void LeftExterior(const unique_ptr<BinaryTreeNode<int>>& tree,
                  vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior) {
    auto pp = &tree;
    while (*pp && ((*pp)->left || (*pp)->right)) {
        exterior.emplace_back(pp);

        if ((*pp)->left) {
            pp = &(*pp)->left;
            continue;
        }
        pp = &(*pp)->right;
    }
}

void RightExterior(const unique_ptr<BinaryTreeNode<int>>& tree,
                   vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior) {
    int init_length = size(exterior);

    auto pp = &tree;
    while (*pp && ((*pp)->left || (*pp)->right)) {
        exterior.emplace_back(pp);

        if ((*pp)->right) {
            pp = &(*pp)->right;
            continue;
        }
        pp = &(*pp)->left;
    }

    reverse(exterior.begin() + init_length, exterior.end());
}

void Leaves(const unique_ptr<BinaryTreeNode<int>>& tree,
            vector<const unique_ptr<BinaryTreeNode<int>>*>& exterior) {
    if (!tree) return;

    stack<const unique_ptr<BinaryTreeNode<int>>*> st;
    st.emplace(&tree);
    while (!st.empty()) {
        auto& p = *st.top();
        st.pop();

        if (!p->left && !p->right) {
            exterior.emplace_back(&p);
            continue;
        }

        if (p->right) st.emplace(&p->right);
        if (p->left) st.emplace(&p->left);
    }
}

vector<int> CreateOutputVector(
    const vector<const unique_ptr<BinaryTreeNode<int>>*>& L) {
    if (find(begin(L), end(L), nullptr) != end(L)) {
        throw TestFailure("Resulting list contains nullptr");
    }
    vector<int> output;
    for (const auto* l : L) {
        output.push_back((*l)->data);
    }
    return output;
}

vector<int> ExteriorBinaryTreeWrapper(
    TimedExecutor& executor, const unique_ptr<BinaryTreeNode<int>>& tree) {
    auto result = executor.Run([&] { return ExteriorBinaryTree(tree); });

    return CreateOutputVector(result);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "tree"};
    return GenericTestMain(args, "data.tsv", &ExteriorBinaryTreeWrapper,
                           DefaultComparator{}, param_names);
}
