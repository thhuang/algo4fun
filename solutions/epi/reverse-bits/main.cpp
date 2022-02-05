#include <epi/generic_test.h>
using namespace std;

void SwapBits(unsigned long long& x, int i, int j) {
    if ((x >> i & 1) == (x >> j & 1)) return;
    x ^= (1ULL << i) | (1ULL << j);
}

unsigned long long ReverseBits(unsigned long long x) {
    for (int i = 0; i < 32; ++i) SwapBits(x, i, 64 - 1 - i);
    return x;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "data.tsv", &ReverseBits, DefaultComparator{},
                           param_names);
}
