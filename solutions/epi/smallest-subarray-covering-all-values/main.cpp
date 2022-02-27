#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Subarray {
    // Represent subarray by starting and ending indices, inclusive.
    int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords) {
    unordered_map<string, int> keyword_index;
    for (int i = 0; i < size(keywords); ++i) keyword_index[keywords[i]] = i;

    Subarray res = {-1, int(size(paragraph))};
    vector<int> min_length(size(keywords), -1);
    vector<int> last_occur(size(keywords), -1);
    for (int i = 0; i < size(paragraph); ++i) {
        string s = paragraph[i];
        auto it = keyword_index.find(s);
        if (it == end(keyword_index)) continue;

        int idx = it->second;
        if (idx == 0) {
            last_occur[idx] = i;
            min_length[idx] = 1;
            continue;
        }

        if (last_occur[idx - 1] == -1) continue;

        last_occur[idx] = i;
        min_length[idx] = min_length[idx - 1] + i - last_occur[idx - 1];

        if (idx == size(keywords) - 1 &&
            min_length.back() < res.end - res.start + 1) {
            res = {i - min_length.back() + 1, i};
        }
    }

    return res;
}

int FindSmallestSequentiallyCoveringSubsetWrapper(
    TimedExecutor& executor, const vector<string>& paragraph,
    const vector<string>& keywords) {
    auto result = executor.Run([&] {
        return FindSmallestSequentiallyCoveringSubset(paragraph, keywords);
    });

    int kw_idx = 0;
    if (result.start < 0) {
        throw TestFailure("Subarray start index is negative");
    }
    int para_idx = result.start;

    while (kw_idx < keywords.size()) {
        if (para_idx >= paragraph.size()) {
            throw TestFailure("Not all keywords are in the generated subarray");
        }
        if (para_idx >= paragraph.size()) {
            throw TestFailure("Subarray end index exceeds array size");
        }
        if (paragraph[para_idx] == keywords[kw_idx]) {
            kw_idx++;
        }
        para_idx++;
    }
    return result.end - result.start + 1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "paragraph", "keywords"};
    return GenericTestMain(args, "data.tsv",
                           &FindSmallestSequentiallyCoveringSubsetWrapper,
                           DefaultComparator{}, param_names);
}
