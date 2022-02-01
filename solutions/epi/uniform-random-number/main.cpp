#include <epi/generic_test.h>
#include <epi/random_sequence_checker.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <functional>
#include <random>
#include <vector>
using namespace std;
int ZeroOneRandom() {
    default_random_engine gen((random_device())());
    uniform_int_distribution<int> dis(0, 1);
    return dis(gen);
}

int UniformRandom(int lower_bound, int upper_bound) {
    int num_slots = upper_bound - lower_bound + 1;
    while (1) {
        int res = 0;
        for (int i = 0; (1 << i) < num_slots; ++i) {
            // ZeroOneRandom is the provided random number generator
            res |= ZeroOneRandom() << i;
        }
        if (res < num_slots) return res + lower_bound;
    }

    return -1;
}

bool UniformRandomRunner(TimedExecutor& executor, int lower_bound,
                         int upper_bound) {
    vector<int> result;
    executor.Run([&] {
        std::generate_n(back_inserter(result), 100000,
                        std::bind(UniformRandom, lower_bound, upper_bound));
    });

    vector<int> sequence;
    std::transform(begin(result), end(result), back_inserter(sequence),
                   [lower_bound](int result) { return result - lower_bound; });
    return CheckSequenceIsUniformlyRandom(result, upper_bound - lower_bound + 1,
                                          0.01);
}

void UniformRandomWrapper(TimedExecutor& executor, int lower_bound,
                          int upper_bound) {
    RunFuncWithRetries(bind(UniformRandomRunner, std::ref(executor),
                            lower_bound, upper_bound));
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"executor", "lower_bound",
                                         "upper_bound"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &UniformRandomWrapper,
                           DefaultComparator{}, param_names);
}
