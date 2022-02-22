#include <epi/generic_test.h>
using namespace std;

int SquareRoot(int k) {
    int l = 0;
    int r = k;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (m > k / m) {
            r = m - 1;
            continue;
        }
        if ((m + 1) > k / (m + 1)) return m;
        l = m + 1;
    }

    return l;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"k"};
    return GenericTestMain(args, "data.tsv", &SquareRoot, DefaultComparator{},
                           param_names);
}
