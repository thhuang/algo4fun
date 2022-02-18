#include <epi/binary_tree_utils.h>
#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>

#include <functional>
#include <istream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

using test_framework::BinaryTreeSerializationTrait;
template <typename T>
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
    int size;
};

const BinaryTreeNode<int>* FindKthNodeBinaryTree(
    const unique_ptr<BinaryTreeNode<int>>& tree, int k) {
    auto iter = tree.get();
    while (iter) {
        if (iter->left && iter->left->size >= k) {
            iter = iter->left.get();
            continue;
        }

        if (iter->left) k -= iter->left->size;
        if (--k == 0) return iter;

        iter = iter->right.get();
    }

    return nullptr;
}

/* const BinaryTreeNode<int>* FindKthNodeBinaryTree( */
/*     const unique_ptr<BinaryTreeNode<int>>& tree, int k) { */
/*     BinaryTreeNode<int>* result = nullptr; */
/*     function<void(BinaryTreeNode<int>*)> search = */
/*         [&](BinaryTreeNode<int>* node) { */
/*             if (!node || result) return; */

/*             search(node->left.get()); */

/*             if (--k == 0) { */
/*                 result = node; */
/*                 return; */
/*             } */

/*             search(node->right.get()); */
/*         }; */

/*     search(tree.get()); */
/*     return result; */
/* } */

namespace test_framework {
template <typename KeyT>
struct SerializationTrait<unique_ptr<BinaryTreeNode<KeyT>>>
    : BinaryTreeSerializationTrait<unique_ptr<BinaryTreeNode<KeyT>>, false> {
    using serialization_type = unique_ptr<BinaryTreeNode<KeyT>>;
    using base =
        BinaryTreeSerializationTrait<unique_ptr<BinaryTreeNode<KeyT>>, false>;

    static serialization_type Parse(const json& json_object) {
        auto tree = base::Parse(json_object);
        InitSize(tree);
        return move(tree);
    }

   private:
    static int InitSize(const serialization_type& node) {
        if (!node) {
            return 0;
        }
        node->size = 1 + InitSize(node->left) + InitSize(node->right);
        return node->size;
    }
};

namespace meta {
template <typename KeyT>
struct IsBinaryTreeImpl<unique_ptr<BinaryTreeNode<KeyT>>> : true_type {};
}  // namespace meta
}  // namespace test_framework

int FindKthNodeBinaryTreeWrapper(const unique_ptr<BinaryTreeNode<int>>& tree,
                                 int k) {
    auto result = FindKthNodeBinaryTree(tree, k);
    if (!result) {
        throw TestFailure("Result can't be nullptr");
    }
    return result->data;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "k"};
    return GenericTestMain(args, "data.tsv", &FindKthNodeBinaryTreeWrapper,
                           DefaultComparator{}, param_names);
}
