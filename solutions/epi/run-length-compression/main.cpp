#include <epi/generic_test.h>
#include <epi/test_failure.h>

#include <cctype>
#include <sstream>
#include <string>
using namespace std;

string Decoding(const string &s) {
    string res;
    for (int l = 0; l < size(s); ++l) {
        int r = l;
        while (isdigit(s[r])) ++r;

        int cnt = stoi(s.substr(l, r - l));
        res.append(cnt, s[r]);
        l = r;
    }
    return res;
}
string Encoding(const string &s) {
    ostringstream ss;
    for (int l = 0; l < size(s); ++l) {
        int r = l;
        int cnt = 0;
        while (s[l] == s[r]) ++r, ++cnt;
        ss << cnt << s[l];
        l = r - 1;
    }

    return ss.str();
}
void RleTester(const string &encoded, const string &decoded) {
    if (Decoding(encoded) != decoded) {
        throw TestFailure("Decoding failed");
    }
    if (Encoding(decoded) != encoded) {
        throw TestFailure("Encoding failed");
    }
}

int main(int argc, char *argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"encoded", "decoded"};
    return GenericTestMain(args, "data.tsv", &RleTester, DefaultComparator{},
                           param_names);
}
