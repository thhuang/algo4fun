#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <random>
using namespace std;

// Assumption: there are at least k elements in the stream.
vector<int> OnlineRandomSample(vector<int>::const_iterator stream_begin,
                               const vector<int>::const_iterator stream_end,
                               int k) {
    vector<int> vec(k);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = *stream_begin++;
    }

    int num_seen = k;
    random_device rd;
    default_random_engine gen(rd());
    for (; stream_begin != stream_end; ++stream_begin, ++num_seen) {
        int chosen_idx = uniform_int_distribution<int>(0, num_seen)(gen);
        if (chosen_idx < k) vec[chosen_idx] = *stream_begin;
    }

    return vec;
}
bool OnlineRandomSamplingRunner(TimedExecutor& executor, vector<int> stream,
                                int k) {
    vector<vector<int>> results;

    executor.Run([&] {
        generate_n(back_inserter(results), 100000,
                   bind(OnlineRandomSample, cbegin(stream), cend(stream), k));
    });

    int total_possible_outcomes = BinomialCoefficient(stream.size(), k);
    sort(begin(stream), end(stream));
    vector<vector<int>> combinations;
    for (int i = 0; i < BinomialCoefficient(stream.size(), k); ++i) {
        combinations.emplace_back(
            ComputeCombinationIdx(stream, stream.size(), k, i));
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

void OnlineRandomSampleWrapper(TimedExecutor& executor,
                               const vector<int>& stream, int k) {
    RunFuncWithRetries(
        bind(OnlineRandomSamplingRunner, ref(executor), cref(stream), k));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "stream", "k"};
    return GenericTestMain(args, "main.cpp", "data.tsv",
                           &OnlineRandomSampleWrapper, DefaultComparator{},
                           param_names);
}
