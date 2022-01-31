#include <epi/generic_test.h>
using namespace std;

long long SwapBits(long long x, int i, int j) {
    if ((x >> i & 1) == (x >> j & 1)) return x;
    return x ^ (1LL << i) ^ (1LL << j);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "i", "j"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &SwapBits,
                           DefaultComparator{}, param_names);
}
