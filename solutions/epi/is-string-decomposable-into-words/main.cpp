#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> DecomposeIntoDictionaryWords(
    const string& domain, const unordered_set<string>& dictionary) {
    vector<int> last_string_length(size(domain), -1);
    for (int i = 0; i < size(domain); ++i) {
        if (string s = domain.substr(0, i + 1); dictionary.count(s)) {
            last_string_length[i] = i + 1;
            continue;
        }

        for (int j = 0; j < i; ++j) {
            if (last_string_length[j] == -1) continue;
            if (string s = domain.substr(j + 1, i - j); dictionary.count(s)) {
                last_string_length[i] = i - j;
                break;
            }
        }
    }

    if (last_string_length.back() == -1) return {};

    vector<string> result;
    int i = size(last_string_length) - 1;
    while (i >= 0) {
        int length = last_string_length[i];
        int from = i - length + 1;
        result.emplace_back(domain.substr(from, length));
        i -= length;
    }

    reverse(begin(result), end(result));

    return result;
}

void DecomposeIntoDictionaryWordsWrapper(
    TimedExecutor& executor, const string& domain,
    const unordered_set<string>& dictionary, bool decomposable) {
    vector<string> result = executor.Run(
        [&] { return DecomposeIntoDictionaryWords(domain, dictionary); });
    if (!decomposable) {
        if (!result.empty()) {
            throw TestFailure("domain is not decomposable");
        }
        return;
    }

    if (any_of(begin(result), end(result),
               [&](const string& s) { return !dictionary.count(s); })) {
        throw TestFailure("Result uses words not in dictionary");
    }

    if (accumulate(begin(result), end(result), string()) != domain) {
        throw TestFailure("Result is not composed into domain");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "domain", "dictionary",
                               "decomposable"};
    return GenericTestMain(args, "data.tsv",
                           &DecomposeIntoDictionaryWordsWrapper,
                           DefaultComparator{}, param_names);
}
