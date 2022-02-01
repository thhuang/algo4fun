#include <epi/generic_test.h>
using namespace std;

long long Reverse(int x) {
    long long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &Reverse,
                           DefaultComparator{}, param_names);
}
