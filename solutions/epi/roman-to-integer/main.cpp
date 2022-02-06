#include <epi/generic_test.h>

#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> kRomanCharToInteger = {
    {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000},
};

int RomanToInteger(const string& s) {
    int sum = kRomanCharToInteger[s.back()];
    for (int i = size(s) - 2; ~i; --i) {
        if (kRomanCharToInteger[s[i]] < kRomanCharToInteger[s[i + 1]]) {
            sum -= kRomanCharToInteger[s[i]];
            continue;
        }
        sum += kRomanCharToInteger[s[i]];
    }
    return sum;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &RomanToInteger,
                           DefaultComparator{}, param_names);
}
