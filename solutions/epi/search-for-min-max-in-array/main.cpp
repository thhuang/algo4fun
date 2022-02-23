#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <sys/wait.h>

#include <algorithm>
using namespace std;

struct MinMax {
    int smallest, largest;
};

MinMax FindMinMax(const vector<int>& A) {
    // assume A is not empty
    auto minmax = MinMax{A[0], A[0]};
    for (int v : A) {
        if (v > minmax.largest) {
            minmax.largest = v;
            continue;
        }
        if (v < minmax.smallest) minmax.smallest = v;
    }

    return minmax;
}

namespace test_framework {
template <>
struct SerializationTrait<MinMax> : UserSerTrait<MinMax, int, int> {};
}  // namespace test_framework

bool operator==(const MinMax& lhs, const MinMax& rhs) {
    return tie(lhs.smallest, lhs.largest) == tie(rhs.smallest, rhs.largest);
}

ostream& operator<<(ostream& out, const MinMax& x) {
    return out << "min: " << x.smallest << ", max: " << x.largest;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &FindMinMax, DefaultComparator{},
                           param_names);
}
