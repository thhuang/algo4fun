#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

int LongestNondecreasingSubsequenceLength(const vector<int>& A) {
    vector<int> result;

    for (int v : A) {
        auto it = upper_bound(begin(result), end(result), v);
        if (it == end(result)) {
            result.emplace_back(v);
            continue;
        }
        *it = v;
    }

    return size(result);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv",
                           &LongestNondecreasingSubsequenceLength,
                           DefaultComparator{}, param_names);
}
