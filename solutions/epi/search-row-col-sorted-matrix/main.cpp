#include <epi/generic_test.h>
using namespace std;

bool MatrixSearch(const vector<vector<int>>& A, int x) {
    int r = 0;
    int c = size(A[0]) - 1;

    while (r < size(A) && c < size(A[r])) {
        if (x < A[r][c]) {
            --c;
            continue;
        }
        if (x > A[r][c]) {
            ++r;
            continue;
        }
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A", "x"};
    return GenericTestMain(args, "data.tsv", &MatrixSearch, DefaultComparator{},
                           param_names);
}
