#include <epi/generic_test.h>

#include <string>
using namespace std;

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
    if (size(t) < size(s)) return -1;
    if (size(s) == 0) return 0;

    const long long kBase = 26;
    long long s_hash = 0;
    long long w_hash = 0;
    long long mul = 1;
    for (int i = 0; i < size(s); ++i) {
        mul *= kBase;
        s_hash = (s_hash + s[i]) * kBase;
        if (i < size(s) - 1) w_hash = (w_hash + t[i]) * kBase;
    }

    for (int i = size(s) - 1; i < size(t); ++i) {
        w_hash = (w_hash + t[i]) * kBase;

        int pos = i - size(s) + 1;
        if (w_hash == s_hash && t.substr(pos, size(s)) == s) return pos;
        w_hash -= t[pos] * mul;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"t", "s"};
    return GenericTestMain(args, "data.tsv", &RabinKarp, DefaultComparator{},
                           param_names);
}
