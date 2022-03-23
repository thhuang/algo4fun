#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <vector>
using namespace std;

struct Item {
    int weight, value;
};

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
    int n = size(items);
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int i = items[0].weight; i <= capacity; ++i) dp[0][i] = items[0].value;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - items[i].weight >= 0) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - items[i].weight] + items[i].value);
            }
        }
    }

    return dp.back().back();
}

namespace test_framework {
template <>
struct SerializationTrait<Item> : UserSerTrait<Item, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"items", "capacity"};
    return GenericTestMain(args, "data.tsv", &OptimumSubjectToCapacity,
                           DefaultComparator{}, param_names);
}
