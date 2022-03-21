#include <epi/bst_node.h>
#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <memory>
#include <vector>
using namespace std;

struct Interval {
    int left, right;
};

vector<int> RangeLookupInBST(const unique_ptr<BstNode<int>>& tree,
                             const Interval& interval) {
    vector<int> result;

    function<void(const unique_ptr<BstNode<int>>&)> search =
        [&](const unique_ptr<BstNode<int>>& node) {
            if (!node) return;

            if (node->data > interval.left) search(node->left);

            if (interval.left <= node->data && node->data <= interval.right)
                result.emplace_back(node->data);

            if (node->data < interval.right) search(node->right);
        };

    search(tree);
    return result;
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {
    static vector<string> GetMetricNames(const string& arg_name) {
        return {FmtStr("length({})", arg_name)};
    }

    static vector<int> GetMetrics(const Interval& x) {
        return {x.right - x.left};
    }
};
}  // namespace test_framework

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"tree", "interval"};
    return GenericTestMain(args, "data.tsv", &RangeLookupInBST,
                           DefaultComparator{}, param_names);
}
