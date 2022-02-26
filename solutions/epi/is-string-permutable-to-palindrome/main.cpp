#include <epi/generic_test.h>

#include <unordered_map>
using namespace std;

bool CanFormPalindrome(const string& s) {
    unordered_map<char, unsigned> char_count;
    for (char c : s) ++char_count[c];

    bool has_odd = false;
    for (auto [_, cnt] : char_count) {
        if (cnt & 1) {
            if (has_odd) return false;
            has_odd = true;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &CanFormPalindrome,
                           DefaultComparator{}, param_names);
}
