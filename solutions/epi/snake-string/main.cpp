#include <epi/generic_test.h>

#include <string>
using namespace std;

string SnakeString(const string& s) {
    string res;
    for (int i = 1; i < size(s); i += 4) res += s[i];
    for (int i = 0; i < size(s); i += 2) res += s[i];
    for (int i = 3; i < size(s); i += 4) res += s[i];
    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"s"};
    return GenericTestMain(args, "data.tsv", &SnakeString, DefaultComparator{},
                           param_names);
}
