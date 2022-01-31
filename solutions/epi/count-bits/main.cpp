#include <epi/generic_test.h>
using namespace std;

short CountBits(unsigned int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &CountBits,
                           DefaultComparator{}, param_names);
}
