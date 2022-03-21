#include <epi/generic_test.h>

#include <cmath>
#include <vector>
using namespace std;

const double SQRT_2 = sqrt(2);

vector<double> GenerateFirstKABSqrt2(int k) {
    if (k < 1) return {};

    vector<double> result{0};
    int i = 0, j = 0;
    while (size(result) < k) {
        if (abs(result[i] + 1 - result[j] - SQRT_2) < 1e-7) {
            result.emplace_back(result[i] + 1);
            ++i, ++j;
            continue;
        }

        result.emplace_back(result[i] + 1 < result[j] + SQRT_2
                                ? result[i++] + 1
                                : result[j++] + SQRT_2);
    }

    return result;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"k"};
    return GenericTestMain(args, "data.tsv", &GenerateFirstKABSqrt2,
                           DefaultComparator{}, param_names);
}
