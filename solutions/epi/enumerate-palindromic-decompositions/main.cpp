#include <epi/generic_test.h>

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> PalindromeDecompositions(const string& text) {
    vector<vector<string>> result;

    vector<string> parts;
    function<bool(const string& s)> is_palindrome =
        [](const string& s) -> bool {
        for (int i = 0; i < size(s) / 2; ++i) {
            if (s[i] != s[size(s) - i - 1]) return false;
        }
        return true;
    };

    function<void(int)> search = [&](int left) -> void {
        if (left == size(text)) {
            result.emplace_back(parts);
            return;
        }

        for (int right = left + 1; right <= size(text); ++right) {
            string sub = text.substr(left, right - left);
            if (!is_palindrome(sub)) continue;

            parts.emplace_back(sub);
            search(right);
            parts.pop_back();
        }
    };

    search(0);
    return result;
}
bool Comp(vector<vector<string>> expected, vector<vector<string>> result) {
    sort(begin(expected), end(expected));
    sort(begin(result), end(result));
    return expected == result;
};

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"text"};
    return GenericTestMain(args, "data.tsv", &PalindromeDecompositions, &Comp,
                           param_names);
}
