#include <epi/generic_test.h>

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int LongestSubarrayWithDistinctEntries(const vector<int>& A) {
    int res = 0;

    unordered_set<int> seen;
    for (int l = 0, r = 0; r < size(A); ++r) {
        if (seen.emplace(A[r]).second) {
            res = max(res, int(size(seen)));
            continue;
        }

        while (true) {
            int li = A[l++];
            if (li == A[r]) break;
            seen.erase(li);
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv",
                           &LongestSubarrayWithDistinctEntries,
                           DefaultComparator{}, param_names);
}
