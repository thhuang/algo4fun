#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <random>
#include <vector>
using namespace std;

vector<int> ComputeRandomPermutation(int n) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    random_device rd;
    default_random_engine gen(rd());
    for (int i = 0; i < perm.size(); ++i) {
        int chosen_idx = uniform_int_distribution<int>(i, perm.size() - 1)(gen);
        swap(perm[i], perm[chosen_idx]);
    }

    return perm;
}

int Factorial(int n) { return n <= 1 ? 1 : n * Factorial(n - 1); }

int PermutationIndex(vector<int> perm) {
    int idx = 0;
    int n = perm.size();
    for (int i = 0; i < perm.size(); ++i) {
        int a = perm[i];
        idx += a * Factorial(n - 1);
        for (int j = i + 1; j < perm.size(); ++j) {
            if (perm[j] > a) {
                --perm[j];
            }
        }
        --n;
    }
    return idx;
}

bool ComputeRandomPermutationRunner(TimedExecutor& executor, int n) {
    vector<vector<int>> results;

    executor.Run([&] {
        for (int i = 0; i < 1000000; ++i) {
            results.emplace_back(ComputeRandomPermutation(n));
        }
    });

    vector<int> sequence;
    for (const vector<int>& result : results) {
        sequence.emplace_back(PermutationIndex(result));
    }
    return CheckSequenceIsUniformlyRandom(sequence, Factorial(n), 0.01);
}

void ComputeRandomPermutationWrapper(TimedExecutor& executor, int n) {
    RunFuncWithRetries(bind(ComputeRandomPermutationRunner, ref(executor), n));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "n"};
    return GenericTestMain(args, "main.cpp", "data.tsv",
                           &ComputeRandomPermutationWrapper,
                           DefaultComparator{}, param_names);
}
