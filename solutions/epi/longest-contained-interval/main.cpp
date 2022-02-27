#include <epi/generic_test.h>

#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int LongestContainedRange(const vector<int>& A) {
    int res = 0;

    unordered_set<int> nums;
    for (int v : A) nums.emplace(v);

    for (int v : A) {
        if (!nums.count(v)) continue;

        int length = 1;
        nums.erase(v);
        for (int i = v + 1; nums.count(i); ++i) ++length, nums.erase(i);
        for (int i = v - 1; nums.count(i); --i) ++length, nums.erase(i);
        res = max(res, length);
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &LongestContainedRange,
                           DefaultComparator{}, param_names);
}
