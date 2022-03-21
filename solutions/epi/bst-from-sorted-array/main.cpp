#include <epi/binary_tree_utils.h>
#include <epi/bst_node.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <memory>
#include <vector>
using namespace std;

unique_ptr<BstNode<int>> AddNode(const vector<int>& vec, int l, int r) {
    if (l > r) return nullptr;

    int m = l + (r - l) / 2;
    return make_unique<BstNode<int>>(vec[m], AddNode(vec, l, m - 1),
                                     AddNode(vec, m + 1, r));
}

unique_ptr<BstNode<int>> BuildMinHeightBSTFromSortedArray(
    const vector<int>& A) {
    return AddNode(A, 0, size(A) - 1);
}

int BuildMinHeightBSTFromSortedArrayWrapper(TimedExecutor& executor,
                                            const vector<int>& A) {
    auto result =
        executor.Run([&] { return BuildMinHeightBSTFromSortedArray(A); });

    if (test_framework::GenerateInorder(result) != A) {
        throw TestFailure("Result binary tree mismatches input array");
    }
    return test_framework::BinaryTreeHeight(result);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A"};
    return GenericTestMain(args, "data.tsv",
                           &BuildMinHeightBSTFromSortedArrayWrapper,
                           DefaultComparator{}, param_names);
}
