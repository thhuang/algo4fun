#include <epi/generic_test.h>
#include <epi/test_failure.h>

#include <algorithm>
#include <string>
using namespace std;

string IntToString(int x) {
    if (!x) return "0";

    string rs;
    for (int i = x; i; i /= 10) {
        rs += '0' + abs(i % 10);
    }

    if (x < 0) rs += '-';

    return {crbegin(rs), crend(rs)};
}

int StringToInt(const string& s) {
    int num = 0;
    for (int i = size(s) - 1, mul = 1; ~i; --i) {
        if (s[i] == '-') {
            num *= -1;
            break;
        }
        if (!isdigit(s[i])) break;
        num += (s[i] - '0') * mul;
        mul *= 10;
    }
    return num;
}

void Wrapper(int x, const string& s) {
    if (stoi(IntToString(x)) != x) {
        throw TestFailure("Int to string conversion failed");
    }

    if (StringToInt(s) != x) {
        throw TestFailure("String to int conversion failed");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "s"};
    return GenericTestMain(args, "data.tsv", &Wrapper, DefaultComparator{},
                           param_names);
}
