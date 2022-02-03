#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <random>
using namespace std;

void RandomSampling(int k, vector<int>* vec_ptr) {
    vector<int>& vec = *vec_ptr;

    random_device rd;
    default_random_engine gen(rd());
    for (int i = 0; i < k; ++i) {
        int chosen_idx = uniform_int_distribution<int>(i, vec.size() - 1)(gen);
        swap(vec[i], vec[chosen_idx]);
    }
}

bool RandomSamplingRunner(TimedExecutor& executor, int k, vector<int> A) {
    vector<vector<int>> results;

    executor.Run([&] {
        for (int i = 0; i < 100000; ++i) {
            RandomSampling(k, &A);
            results.emplace_back(begin(A), begin(A) + k);
        }
    });

    int total_possible_outcomes = BinomialCoefficient(A.size(), k);
    sort(begin(A), end(A));
    vector<vector<int>> combinations;
    for (int i = 0; i < BinomialCoefficient(A.size(), k); ++i) {
        combinations.emplace_back(ComputeCombinationIdx(A, A.size(), k, i));
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

void RandomSamplingWrapper(TimedExecutor& executor, int k,
                           const vector<int>& A) {
    RunFuncWithRetries(bind(RandomSamplingRunner, ref(executor), k, cref(A)));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "k", "A"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &RandomSamplingWrapper,
                           DefaultComparator{}, param_names);
}
