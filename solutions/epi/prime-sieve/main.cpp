#include <epi/generic_test.h>
using namespace std;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
    vector<int> primes;
    vector<bool> is_not_prime(n + 1, false);
    for (int i = 2; i <= n; ++i) {
        if (is_not_prime[i]) continue;

        primes.push_back(i);

        // i^2 might overflow!
        for (auto j = (long long)i * i; j <= n; j += i) {
            is_not_prime[j] = true;
        }
    }

    return primes;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"n"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &GeneratePrimes,
                           DefaultComparator{}, param_names);
}
