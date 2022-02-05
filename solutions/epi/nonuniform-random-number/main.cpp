#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>
using namespace std;

int NonuniformRandomNumberGeneration(const vector<int>& values,
                                     const vector<double>& probabilities) {
    vector<double> accu_prob;
    partial_sum(cbegin(probabilities), cend(probabilities),
                back_inserter(accu_prob));

    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> dist(0, 1);

    double random_num = dist(gen);
    auto iter = upper_bound(cbegin(accu_prob), cend(accu_prob), random_num);
    auto idx = distance(cbegin(accu_prob), iter);

    return values[idx];
}

bool NonuniformRandomNumberGenerationRunner(
    TimedExecutor& executor, const vector<int>& values,
    const vector<double>& probabilities) {
    constexpr int kN = 1000000;
    vector<int> results;

    executor.Run([&] {
        for (int i = 0; i < kN; ++i) {
            results.emplace_back(
                NonuniformRandomNumberGeneration(values, probabilities));
        }
    });

    unordered_map<int, int> counts;
    for (int result : results) {
        ++counts[result];
    }
    for (int i = 0; i < values.size(); ++i) {
        const int v = values[i];
        const double p = probabilities[i];
        if (kN * p < 50 || kN * (1.0 - p) < 50) {
            continue;
        }
        const double sigma = sqrt(kN * p * (1.0 - p));
        if (abs(counts[v] - (p * kN)) > 5 * sigma) {
            return false;
        }
    }
    return true;
}

void NonuniformRandomNumberGenerationWrapper(
    TimedExecutor& executor, const vector<int>& values,
    const vector<double>& probabilities) {
    RunFuncWithRetries(bind(NonuniformRandomNumberGenerationRunner,
                            ref(executor), cref(values), cref(probabilities)));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "values", "probabilities"};
    return GenericTestMain(args, "data.tsv",
                           &NonuniformRandomNumberGenerationWrapper,
                           DefaultComparator{}, param_names);
}
