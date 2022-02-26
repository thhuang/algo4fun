#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Subarray {
    int start, end;

    int Length() { return end - start + 1; }
};

Subarray FindSmallestSubarrayCoveringSet(
    const vector<string> &paragraph, const unordered_set<string> &keywords) {
    Subarray subarray{0, int(size(paragraph))};
    unordered_map<string, int> seen;

    for (int l = 0, r = 0; r < size(paragraph); ++r) {
        string sr = paragraph[r];
        if (keywords.count(sr)) ++seen[sr];

        while (size(seen) == size(keywords)) {
            string sl = paragraph[l];
            if (r - l + 1 < subarray.Length()) subarray = {l, r};
            if (seen.count(sl) && --seen[sl] == 0) seen.erase(sl);
            ++l;
        }
    }

    return subarray;
}

int FindSmallestSubarrayCoveringSetWrapper(
    TimedExecutor &executor, const vector<string> &paragraph,
    const unordered_set<string> &keywords) {
    unordered_set<string> copy = keywords;

    auto result = executor.Run(
        [&] { return FindSmallestSubarrayCoveringSet(paragraph, keywords); });

    if (result.start < 0 || result.start >= paragraph.size() ||
        result.end < 0 || result.end >= paragraph.size() ||
        result.start > result.end) {
        throw TestFailure("Index out of range");
    }

    for (int i = result.start; i <= result.end; i++) {
        copy.erase(paragraph[i]);
    }

    if (!copy.empty()) {
        throw TestFailure("Not all keywords are in the range");
    }

    return result.end - result.start + 1;
}

int main(int argc, char *argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "paragraph", "keywords"};
    return GenericTestMain(args, "data.tsv",
                           &FindSmallestSubarrayCoveringSetWrapper,
                           DefaultComparator{}, param_names);
}
