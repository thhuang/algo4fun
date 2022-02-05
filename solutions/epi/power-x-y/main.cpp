#include <epi/generic_test.h>
using namespace std;

double Power(double x, int y) {
    if (y < 0) {
        x = 1.0 / x;
        y = -y;
    }

    double res = 1.0;
    while (y) {
        if (y & 1) res *= x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x", "y"};
    return GenericTestMain(args, "data.tsv", &Power, DefaultComparator{},
                           param_names);
}
