#include <epi/generic_test.h>
using namespace std;

unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    unsigned long long y = x & 1 ? x + 1 : x;
    unsigned long long mask = y & ~(y - 1);
    return x ^ mask ^ (mask >> 1);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "data.tsv", &ClosestIntSameBitCount,
                           DefaultComparator{}, param_names);
}
