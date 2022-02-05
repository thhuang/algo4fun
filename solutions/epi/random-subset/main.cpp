#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <random>
using namespace std;

// Returns a random k-sized subset of {0, 1, ..., n - 1}.
vector<int> RandomSubset(int n, int k) {
    random_device rd;
    default_random_engine gen(rd());
    unordered_map<int, int> modified_candidates;
    vector<int> subset(k);
    for (int i = 0; i < k; ++i) {
        int j = uniform_int_distribution<int>(i, n - 1)(gen);

        int a = i;
        if (modified_candidates.count(i)) a = modified_candidates[i];

        int b = j;
        if (modified_candidates.count(j)) b = modified_candidates[j];

        subset[i] = b;
        modified_candidates[j] = a;
    }

    return subset;
}

bool RandomSubsetRunner(TimedExecutor& executor, int n, int k) {
    using namespace test_framework;
    vector<vector<int>> results;

    executor.Run([&] {
        generate_n(back_inserter(results), 100000, bind(RandomSubset, n, k));
    });

    int total_possible_outcomes = BinomialCoefficient(n, k);
    vector<int> A(n);
    iota(begin(A), end(A), 0);
    vector<vector<int>> combinations;
    for (int i = 0; i < BinomialCoefficient(n, k); ++i) {
        combinations.emplace_back(ComputeCombinationIdx(A, n, k, i));
    }
    vector<int> sequence;
    for (vector<int> result : results) {
        sort(begin(result), end(result));
        sequence.emplace_back(
            distance(begin(combinations),
                     find(begin(combinations), end(combinations), result)));
    }
    return CheckSequenceIsUniformlyRandom(sequence, total_possible_outcomes,
                                          0.01);
}

void RandomSubsetWrapper(TimedExecutor& executor, int n, int k) {
    RunFuncWithRetries(bind(RandomSubsetRunner, ref(executor), n, k));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "n", "k"};
    return GenericTestMain(args, "data.tsv", &RandomSubsetWrapper,
                           DefaultComparator{}, param_names);
}
