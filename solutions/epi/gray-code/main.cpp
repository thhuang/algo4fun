#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <vector>
using namespace std;

vector<int> GrayCode(int num_bits) {
    vector<int> result = {0};

    while (num_bits--) {
        int n = size(result);
        for (int i = 0; i < n; ++i) {
            result[i] <<= 1;
        }
        for (int i = n - 1; ~i; --i) {
            result.emplace_back(result[i] + 1);
        }
    }

    return result;
}

bool DiffersByOneBit(int x, int y) {
    int bit_difference = x ^ y;
    return bit_difference && !(bit_difference & (bit_difference - 1));
}

void GrayCodeWrapper(TimedExecutor& executor, int num_bits) {
    vector<int> result = executor.Run([&] { return GrayCode(num_bits); });

    int expected_size = (1 << num_bits);
    if (result.size() != expected_size) {
        throw TestFailure("Length mismatch: expected " +
                          to_string(expected_size) + ", got " +
                          to_string(result.size()));
    }
    for (int i = 1; i < result.size(); i++)
        if (!DiffersByOneBit(result[i - 1], result[i])) {
            if (result[i - 1] == result[i]) {
                throw TestFailure("Two adjacent entries are equal");
            } else {
                throw TestFailure(
                    "Two adjacent entries differ by more than 1 bit");
            }
        }

    sort(begin(result), end(result));
    auto uniq = unique(begin(result), end(result));
    if (uniq != end(result)) {
        throw TestFailure("Not all entries are distinct: found " +
                          to_string(distance(uniq, end(result))) +
                          " duplicates");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "num_bits"};
    return GenericTestMain(args, "data.tsv", &GrayCodeWrapper,
                           DefaultComparator{}, param_names);
}
