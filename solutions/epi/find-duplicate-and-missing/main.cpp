#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
using namespace std;

struct DuplicateAndMissing {
    int duplicate, missing;
};

DuplicateAndMissing FindDuplicateMissing(const vector<int>& A) {
    int min_val = 0;
    int max_val = size(A) - 1;

    int d_xor_m = 0;
    int d_minus_m = 0;
    for (int i = 0; i < size(A); ++i) {
        d_xor_m ^= i ^ A[i];
        d_minus_m += A[i] - i;
    }

    int first_diff_digit = d_xor_m & ~(d_xor_m - 1);
    int a = 0;
    for (int i = 0; i < size(A); ++i) {
        if (i & first_diff_digit) a ^= i;
        if (A[i] & first_diff_digit) a ^= A[i];
    }
    int b = a ^ d_xor_m;

    if (a - b == d_minus_m) return {a, b};
    return {b, a};
}

namespace test_framework {
template <>
struct SerializationTrait<DuplicateAndMissing>
    : UserSerTrait<DuplicateAndMissing, int, int> {};
}  // namespace test_framework

bool operator==(const DuplicateAndMissing& lhs,
                const DuplicateAndMissing& rhs) {
    return tie(lhs.duplicate, lhs.missing) == tie(rhs.duplicate, rhs.missing);
}

ostream& operator<<(ostream& out, const DuplicateAndMissing& x) {
    return out << "duplicate: " << x.duplicate << ", missing: " << x.missing;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &FindDuplicateMissing,
                           DefaultComparator{}, param_names);
}
