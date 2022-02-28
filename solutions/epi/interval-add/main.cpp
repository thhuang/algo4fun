#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <vector>
using namespace std;

struct Interval {
    int left, right;
};

vector<Interval> AddInterval(const vector<Interval>& disjoint_intervals,
                             Interval new_interval) {
    vector<Interval> result;
    size_t i = 0;

    while (i < size(disjoint_intervals) &&
           disjoint_intervals[i].right < new_interval.left)
        result.emplace_back(disjoint_intervals[i++]);

    while (i < size(disjoint_intervals) &&
           disjoint_intervals[i].left <= new_interval.right) {
        new_interval = {
            min(new_interval.left, disjoint_intervals[i].left),
            max(new_interval.right, disjoint_intervals[i].right),
        };
        ++i;
    }
    result.emplace_back(new_interval);

    copy(begin(disjoint_intervals) + i, end(disjoint_intervals),
         back_inserter(result));

    return result;
}

namespace test_framework {
template <>
struct SerializationTrait<Interval> : UserSerTrait<Interval, int, int> {
    static vector<string> GetMetricNames(const string& arg_name) {
        return {FmtStr("length({})", arg_name)};
    }

    static vector<int> GetMetrics(const Interval& x) {
        return {x.right - x.left};
    }
};
}  // namespace test_framework

bool operator==(const Interval& a, const Interval& b) {
    return a.left == b.left && a.right == b.right;
}

ostream& operator<<(ostream& out, const Interval& i) {
    return PrintTo(out, make_tuple(i.left, i.right));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"disjoint_intervals", "new_interval"};
    return GenericTestMain(args, "data.tsv", &AddInterval, DefaultComparator{},
                           param_names);
}
