#include <epi/generic_test.h>

#include <cmath>
using namespace std;

double SquareRoot(double k) {
    // f(x) = x^2 - k
    // df/dx = 2x
    // x1 = x0 - f/f' = x0 - (x0^2 - k) / 2x0 = x0 - 0.5 * x0 + k / 2 / x0
    double x0 = 10;
    while (true) {
        double x1 = x0 - 0.5 * (x0 - k / x0);
        if (abs(x1 - x0) < 1e-6) return x1;
        x0 = x1;
    }

    return 0.0;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"x"};
    return GenericTestMain(args, "data.tsv", &SquareRoot, DefaultComparator{},
                           param_names);
}
