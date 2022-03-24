#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

bool HasTwoSum(const vector<int>& A, int t) {
    // assume A is sorted
    for (int l = 0, r = size(A) - 1; l <= r;) {
        int sum = A[l] + A[r];
        if (sum < t) {
            ++l;
            continue;
        }
        if (sum > t) {
            --r;
            continue;
        }
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "t"};
    return GenericTestMain(args, "data.tsv", &HasTwoSum, DefaultComparator{},
                           param_names);
}
