#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>

#include <memory>
#include <stack>
#include <vector>
using namespace std;

struct Payload {
    BinaryTreeNode<int>* node;
    bool seen;
};

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<int> result;
    stack<Payload> st;
    st.push({tree.get(), false});

    while (!st.empty()) {
        auto payload = st.top();
        st.pop();

        if (!payload.node) continue;
        if (payload.seen) {
            result.push_back(payload.node->data);
            continue;
        }

        st.push({payload.node->right.get(), false});
        st.push({payload.node, true});
        st.push({payload.node->left.get(), false});
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &InorderTraversal,
                           DefaultComparator{}, param_names);
}
