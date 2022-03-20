
#pragma once

#include <epi/binary_tree_utils.h>
#include <epi/serialization_traits.h>

#include <memory>

using std::unique_ptr;

template <typename T>
struct BstNode {
    T data;
    unique_ptr<BstNode<T>> left, right;

    explicit BstNode(const T& data) : data(data) {}

    BstNode(T data, unique_ptr<BstNode<T>> left, unique_ptr<BstNode<T>> right)
        : data(data), left(std::move(left)), right(std::move(right)) {}
};

DECLARE_BINARY_TREE_TYPE(KeyT, std::unique_ptr<BstNode<KeyT>>, false)
