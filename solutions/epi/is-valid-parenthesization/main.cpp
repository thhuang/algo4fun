#include <epi/generic_test.h>

using namespace std;

bool IsWellFormed(const string& s) {
    map<char, char> parenthesis_pair = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    stack<char> seen;
    for (char c : s) {
        if (!parenthesis_pair.count(c)) {
            seen.push(c);
            continue;
        }
        if (seen.empty()) return false;
        if (seen.top() != parenthesis_pair[c]) return false;
        seen.pop();
    }

    return seen.empty();
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &IsWellFormed, DefaultComparator{},
                           param_names);
}
