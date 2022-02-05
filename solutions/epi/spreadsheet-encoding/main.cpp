#include <epi/generic_test.h>

#include <algorithm>
#include <string>
using namespace std;

int SSDecodeColID(const string& col) {
    return accumulate(col.begin(), col.end(), 0,
                      [](int num, char c) { return num * 26 + c - 'A' + 1; });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"col"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &SSDecodeColID,
                           DefaultComparator{}, param_names);
}
