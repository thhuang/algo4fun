#include <epi/generic_test.h>
using namespace std;

unsigned long long Add(unsigned long long x, unsigned long long y) {
    while (y) {
        auto carry = x & y;
        x ^= y;
        y = carry << 1;
    }
    return x;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0;
    while (x) {
        if (x & 1) sum = Add(sum, y);
        x >>= 1, y <<= 1;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "y"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &Multiply,
                           DefaultComparator{}, param_names);
}
