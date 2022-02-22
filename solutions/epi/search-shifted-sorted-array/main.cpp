#include <epi/generic_test.h>
using namespace std;

int SearchSmallest(const vector<int>& A) {
    int l = 0;
    int r = size(A) - 1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (A[l] <= A[m] && A[m] <= A[r]) return l;
        if (A[l] > A[m] && A[m] < A[r]) {
            r = m;
            continue;
        }
        l = m + 1;
    }

    return r;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &SearchSmallest,
                           DefaultComparator{}, param_names);
}
