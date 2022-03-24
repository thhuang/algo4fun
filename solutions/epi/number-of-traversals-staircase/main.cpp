#include <epi/generic_test.h>
using namespace std;

int NumberOfWaysToTop(int top, int maximum_step) {
    vector<int> dp(top + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < top; ++i) {
        for (int j = 1; j <= maximum_step; ++j) {
            if (i + j <= top) {
                dp[i + j] += dp[i];
            }
        }
    }

    return dp[top];
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"top", "maximum_step"};
    return GenericTestMain(args, "data.tsv", &NumberOfWaysToTop,
                           DefaultComparator{}, param_names);
}
