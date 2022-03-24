#include <epi/generic_test.h>

#include <vector>
using namespace std;

int MaximumRevenue(const vector<int>& coins) {
    int n = size(coins);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) dp[i][i] = coins[i];
    for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = max(coins[i], coins[i + 1]);
    for (int length = 3; length <= n; ++length) {
        for (int l = 0; l + length - 1 < n; ++l) {
            int r = l + length - 1;
            dp[l][r] = max(coins[l] + min(dp[l + 1][r - 1], dp[l + 2][r]),
                           coins[r] + min(dp[l][r - 2], dp[l + 1][r - 1]));
        }
    }

    return dp[0][n - 1];
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"coins"};
    return GenericTestMain(args, "data.tsv", &MaximumRevenue,
                           DefaultComparator{}, param_names);
}
