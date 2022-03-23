#include <epi/generic_test.h>

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

int MinimumPathWeight(const vector<vector<int>>& triangle) {
    if (empty(triangle)) return 0;

    int n = size(triangle);
    vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += triangle[i][j];
        }
    }

    return *min_element(dp.back().begin(), dp.back().end());
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"triangle"};
    return GenericTestMain(args, "data.tsv", &MinimumPathWeight,
                           DefaultComparator{}, param_names);
}
