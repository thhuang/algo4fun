#include <epi/generic_test.h>
using namespace std;

bool IsPalindrome(const string& s) {
    for (int l = 0, r = size(s) - 1; l < r; ++l, --r) {
        if (!isalnum(s[l])) {
            ++r;
            continue;
        }
        if (!isalnum(s[r])) {
            --l;
            continue;
        }
        if (tolower(s[l]) != tolower(s[r])) return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &IsPalindrome, DefaultComparator{},
                           param_names);
}
