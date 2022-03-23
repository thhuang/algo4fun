#include <epi/generic_test.h>

#include <vector>
using namespace std;

int FindMaximumSubarray(const vector<int>& A) {
    if (empty(A)) return 0;

    int max_sum = 0;
    int max_end = 0;
    for (int v : A) {
        max_end = max(max_end + v, v);
        max_sum = max(max_sum, max_end);
    }

    return max_sum;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &FindMaximumSubarray,
                           DefaultComparator{}, param_names);
}
