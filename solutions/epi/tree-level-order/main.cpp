#include <epi/binary_tree_node.h>
#include <epi/generic_test.h>
using namespace std;

struct NodeWithOrder {
    BinaryTreeNode<int>* node;
    int order;
};

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
    vector<vector<int>> res;
    queue<NodeWithOrder> q;
    q.push({tree.get(), 0});

    while (!q.empty()) {
        auto payload = q.front();
        q.pop();

        if (!payload.node) continue;

        while (payload.order >= size(res)) res.push_back(vector<int>());
        res[payload.order].push_back(payload.node->data);

        q.push({payload.node->left.get(), payload.order + 1});
        q.push({payload.node->right.get(), payload.order + 1});
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree"};
    return GenericTestMain(args, "data.tsv", &BinaryTreeDepthOrder,
                           DefaultComparator{}, param_names);
}
