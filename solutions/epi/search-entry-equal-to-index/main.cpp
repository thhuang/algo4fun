#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>
using namespace std;

int SearchEntryEqualToItsIndex(const vector<int>& A) {
    int l = 0;
    int r = size(A) - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (A[m] < m) {
            l = m + 1;
            continue;
        }
        if (A[m] > m) {
            r = m - 1;
            continue;
        }
        return m;
    }

    return -1;
}
void SearchEntryEqualToItsIndexWrapper(TimedExecutor& executor,
                                       const vector<int>& A) {
    int result = executor.Run([&] { return SearchEntryEqualToItsIndex(A); });

    if (result != -1) {
        if (A[result] != result) {
            throw TestFailure("Entry does not equal to its index");
        }
    } else {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == i) {
                throw TestFailure("There are entries which equal to its index");
            }
        }
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A"};
    return GenericTestMain(args, "data.tsv", &SearchEntryEqualToItsIndexWrapper,
                           DefaultComparator{}, param_names);
}
