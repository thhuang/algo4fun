#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <vector>
using namespace std;

struct Interval {
    int left, right;
};

int FindMinimumVisits(vector<Interval> intervals) {
    if (empty(intervals)) return 0;

    sort(begin(intervals), end(intervals),
         [](const Interval& a, const Interval& b) -> bool {
             if (a.right != b.right) return a.right < b.right;
             return a.left < b.left;
         });

    int num_points = 1;
    int point = intervals[0].right;
    for (auto interval : intervals) {
        if (interval.left <= point) continue;

        ++num_points;
        point = interval.right;
    }

    return num_points;
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"intervals"};
    return GenericTestMain(args, "data.tsv", &FindMinimumVisits,
                           DefaultComparator{}, param_names);
}
