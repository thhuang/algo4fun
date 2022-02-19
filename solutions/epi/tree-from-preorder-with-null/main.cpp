#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
#include <epi/timed_executor.h>
using namespace std;

struct Payload {
    BinaryTreeNode<int>* node;
    bool has_left;

    Payload(BinaryTreeNode<int>* node, bool has_left)
        : node(node), has_left(has_left) {}
};

unique_ptr<BinaryTreeNode<int>> ReconstructPreorder(
    const vector<int*>& preorder) {
    if (preorder.empty() || preorder[0] == nullptr) return nullptr;

    auto tree = make_unique<BinaryTreeNode<int>>(*preorder[0]);

    stack<Payload> st;
    st.emplace(tree.get(), false);
    for (int i = 1; i < size(preorder); ++i) {
        auto payload = st.top();
        st.pop();

        if (!payload.has_left) {
            st.emplace(payload.node, true);

            if (preorder[i] == nullptr) continue;
            payload.node->left = make_unique<BinaryTreeNode<int>>(*preorder[i]);
            st.emplace(payload.node->left.get(), false);

            continue;
        }

        if (preorder[i] == nullptr) continue;
        payload.node->right = make_unique<BinaryTreeNode<int>>(*preorder[i]);
        st.emplace(payload.node->right.get(), false);
    }

    return tree;
}

unique_ptr<BinaryTreeNode<int>> ReconstructPreorderWrapper(
    TimedExecutor& executor, const vector<string>& preorder) {
    vector<int> values;
    vector<int*> ptrs;
    values.reserve(preorder.size());
    for (auto& s : preorder) {
        if (s == "null") {
            ptrs.push_back(nullptr);
        } else {
            int i = stoi(s);
            values.push_back(i);
            ptrs.push_back(&values.back());
        }
    }

    return executor.Run([&] { return ReconstructPreorder(ptrs); });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "preorder"};
    return GenericTestMain(args, "data.tsv", &ReconstructPreorderWrapper,
                           DefaultComparator{}, param_names);
}
