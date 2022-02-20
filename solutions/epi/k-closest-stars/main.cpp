#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_utils.h>

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct Star {
    bool operator<(const Star& that) const {
        return Distance() < that.Distance();
    }

    double Distance() const { return sqrt(x * x + y * y + z * z); }

    double x, y, z;
};

vector<Star> FindClosestKStars(vector<Star>::const_iterator stars_begin,
                               const vector<Star>::const_iterator& stars_end,
                               int k) {
    vector<Star> result;

    priority_queue<Star> max_heap;
    for (auto iter = stars_begin; iter != stars_end; ++iter) {
        max_heap.emplace(*iter);
        if (size(max_heap) <= k) continue;
        max_heap.pop();
    }

    while (!empty(max_heap)) {
        result.emplace_back(max_heap.top());
        max_heap.pop();
    }

    return result;
}

namespace test_framework {
template <>
struct SerializationTrait<Star> : UserSerTrait<Star, double, double, double> {};
}  // namespace test_framework

ostream& operator<<(ostream& out, const Star& s) { return out << s.Distance(); }

bool Comp(const vector<double>& expected, vector<Star> output) {
    if (output.size() != expected.size()) {
        return false;
    }

    sort(begin(output), end(output));

    for (int i = 0; i < output.size(); ++i) {
        if (!DefaultComparator()(output[i].Distance(), expected[i])) {
            return false;
        }
    }
    return true;
}

vector<Star> FindClosestKStarsWrapper(const vector<Star>& stars, int k) {
    return FindClosestKStars(cbegin(stars), cend(stars), k);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"stars", "k"};
    return GenericTestMain(args, "data.tsv", &FindClosestKStarsWrapper, &Comp,
                           param_names);
}
