#include <epi/generic_test.h>

#include <string>
using namespace std;

bool IsPalindromic(const string& s) {
    for (int i = 0; i < size(s) / 2; ++i) {
        if (s[i] != s[size(s) - 1 - i]) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &IsPalindromic,
                           DefaultComparator{}, param_names);
}
