#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <set>
#include <vector>
using namespace std;

void EvenOdd(vector<int>* p_vec) {
    vector<int>& vec = *p_vec;
    int next_even = 0;
    int next_odd = vec.size() - 1;

    while (next_even < next_odd) {
        if (vec[next_even] % 2 == 0) {
            ++next_even;
            continue;
        }

        swap(vec[next_even], vec[next_odd--]);
    }
}

void EvenOddWrapper(TimedExecutor& executor, vector<int> A) {
    multiset<int> before(begin(A), end(A));

    executor.Run([&] { EvenOdd(&A); });

    bool in_odd = false;
    for (int a : A) {
        if (a % 2 == 0) {
            if (in_odd) {
                throw TestFailure("Even elements appear in odd part");
            }
        } else {
            in_odd = true;
        }
    }

    multiset<int> after(begin(A), end(A));
    if (before != after) {
        throw TestFailure("Elements mismatch");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "A"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &EvenOddWrapper,
                           DefaultComparator{}, param_names);
}
