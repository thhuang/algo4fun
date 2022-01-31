#include <epi/generic_test.h>
using namespace std;

short Parity(unsigned long long x) {
    for (int bits = 32; bits; bits >>= 1) {
        x ^= x >> bits; 
    }
    return x & 1;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &Parity,
                           DefaultComparator{}, param_names);
}
