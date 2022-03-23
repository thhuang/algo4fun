#include <epi/generic_test.h>

#include <string>
#include <vector>
using namespace std;

int LevenshteinDistance(const string& A, const string& B) {
    vector<vector<int>> dp(size(A) + 1, vector<int>(size(B) + 1));

    for (int i = 0; i <= size(A); ++i) dp[i][0] = i;
    for (int i = 0; i <= size(B); ++i) dp[0][i] = i;

    for (int i = 1; i <= size(A); ++i) {
        for (int j = 1; j <= size(B); ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }

    return dp.back().back();
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "B"};
    return GenericTestMain(args, "data.tsv", &LevenshteinDistance,
                           DefaultComparator{}, param_names);
}
