#include <epi/generic_test.h>

#include <vector>
using namespace std;

bool HasThreeSum(vector<int> A, int t) {
    sort(begin(A), end(A));
    for (int i = 0; i < size(A); ++i) {
        int l = i, r = size(A) - 1;
        while (l <= r) {
            int sum = A[i] + A[l] + A[r];
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
    }
    return false;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "t"};
    return GenericTestMain(args, "data.tsv", &HasThreeSum, DefaultComparator{},
                           param_names);
}
