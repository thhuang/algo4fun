#include <epi/generic_test.h>
using namespace std;

int NumberOfWays(int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n", "m"};
    return GenericTestMain(args, "data.tsv", &NumberOfWays, DefaultComparator{},
                           param_names);
}
