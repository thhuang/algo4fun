#include <epi/generic_test.h>
using namespace std;

int SearchFirstOfK(const vector<int>& A, int k) {
    if (A.empty()) return -1;

    int l = 0;
    int r = size(A) - 1;

    while (l < r) {
        int m = l + (r - l) / 2;
        if (k > A[m]) {
            l = m + 1;
            continue;
        }
        r = m;
    }

    return A[r] == k ? r : -1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "k"};
    return GenericTestMain(args, "data.tsv", &SearchFirstOfK,
                           DefaultComparator{}, param_names);
}
