#include <epi/generic_test.h>

#include <vector>
using namespace std;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
    vector<int> dp(final_score + 1, 0);
    dp[0] = 1;

    for (int v : individual_play_scores) {
        for (int i = 0; i < final_score; ++i) {
            if (i + v > final_score) continue;
            dp[i + v] += dp[i];
        }
    }

    return dp[final_score];
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"final_score", "individual_play_scores"};
    return GenericTestMain(args, "data.tsv", &NumCombinationsForFinalScore,
                           DefaultComparator{}, param_names);
}
