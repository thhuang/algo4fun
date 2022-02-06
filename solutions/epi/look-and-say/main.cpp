#include <epi/generic_test.h>

#include <string>
using namespace std;

string NextNumber(const string& s);

string LookAndSay(int n) {
    string s = "1";
    for (int i = 1; i < n; ++i) s = NextNumber(s);
    return s;
}

string NextNumber(const string& s) {
    string res;
    for (int i = 0; i < size(s); ++i) {
        int cnt = 1;
        while (i + 1 < size(s) && s[i + 1] == s[i]) ++i, ++cnt;
        res += to_string(cnt) + s[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n"};
    return GenericTestMain(args, "data.tsv", &LookAndSay, DefaultComparator{},
                           param_names);
}
