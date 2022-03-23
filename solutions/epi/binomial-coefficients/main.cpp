#include <epi/generic_test.h>

#include <vector>
using namespace std;

int ComputeBinomialCoefficient(int n, int k) {
    k = min(k, n - k);

    vector<vector<int>> dp(n + 1, vector<int>(k + 2, 0));
    dp[0][1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k && j <= i + 2; ++j) {
            int row = i;
            int col = j + 1;
            dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
        }
    }

    return dp.back().back();
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n", "k"};
    return GenericTestMain(args, "data.tsv", &ComputeBinomialCoefficient,
                           DefaultComparator{}, param_names);
}
