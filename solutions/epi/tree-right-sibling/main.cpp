#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/timed_executor.h>
using namespace std;

using test_framework::BinaryTreeSerializationTrait;
template <typename T>
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
    BinaryTreeNode<T>* next = nullptr;  // Populates this field.

    explicit BinaryTreeNode(T data) : data(data){};
};

void ConstructRightSibling(BinaryTreeNode<int>* tree) {
    if (!tree) return;
    for (auto pi = tree; pi->left; pi = pi->left.get()) {
        for (auto pj = pi; pj; pj = pj->next) {
            pj->left->next = pj->right.get();
            if (pj->next) pj->right->next = pj->next->left.get();
        }
    }
}

/* struct Payload { */
/*     BinaryTreeNode<int>* node; */
/*     int depth; */

/*     Payload(BinaryTreeNode<int>* node, int depth) : node(node), depth(depth)
 * {} */
/* }; */
/* void ConstructRightSibling(BinaryTreeNode<int>* tree) { */
/*     queue<Payload> q; */
/*     q.emplace(tree, 0); */
/*     auto prev_payload = Payload(nullptr, -1); */

/*     while (!q.empty()) { */
/*         auto payload = q.front(); */
/*         q.pop(); */

/*         if (!payload.node) continue; */

/*         if (payload.depth == prev_payload.depth) { */
/*             prev_payload.node->next = payload.node; */
/*         } */

/*         prev_payload = payload; */
/*         q.emplace(payload.node->left.get(), payload.depth + 1); */
/*         q.emplace(payload.node->right.get(), payload.depth + 1); */
/*     } */
/* } */

namespace test_framework {
template <>
struct SerializationTrait<unique_ptr<BinaryTreeNode<int>>>
    : BinaryTreeSerializationTrait<unique_ptr<BinaryTreeNode<int>>, false> {};
}  // namespace test_framework

vector<vector<int>> ConstructRightSiblingWrapper(
    TimedExecutor& executor, unique_ptr<BinaryTreeNode<int>>& tree) {
    executor.Run([&] { ConstructRightSibling(tree.get()); });

    vector<vector<int>> result;
    auto level_start = tree.get();
    while (level_start) {
        result.emplace_back();
        auto level_iter = level_start;
        while (level_iter) {
            result.back().push_back(level_iter->data);
            level_iter = level_iter->next;
        }
        level_start = level_start->left.get();
    }
    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "tree"};
    return GenericTestMain(args, "data.tsv", &ConstructRightSiblingWrapper,
                           DefaultComparator{}, param_names);
}
