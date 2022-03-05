#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/timed_executor.h>

#include <vector>
using namespace std;

struct Interval {
    struct Endpoint {
        bool is_closed;
        int val;
    };

    Endpoint left, right;
};

vector<Interval> UnionOfIntervals(vector<Interval> intervals) {
    if (empty(intervals)) return {};

    sort(begin(intervals), end(intervals), [](Interval a, Interval b) {
        if (a.left.val != b.left.val) return a.left.val < b.left.val;
        if (a.left.is_closed != b.left.is_closed) return a.left.is_closed;
        if (a.right.val != b.right.val) return a.right.val < b.right.val;
        if (a.right.is_closed != b.right.is_closed) return a.right.is_closed;
        return false;
    });

    vector<Interval> result = {intervals.front()};
    for (Interval v : intervals) {
        Interval& last_interval = result.back();

        if (last_interval.right.val < v.left.val ||
            (last_interval.right.val == v.left.val &&
             !last_interval.right.is_closed && !v.left.is_closed)) {
            result.emplace_back(v);
            continue;
        }

        if (last_interval.right.val == v.right.val) {
            last_interval.right.is_closed |= v.right.is_closed;
            continue;
        }

        if (last_interval.right.val < v.right.val) {
            last_interval.right = v.right;
            continue;
        }
    }

    return result;
}
struct FlatInterval {
    int left_val;
    bool left_is_closed;
    int right_val;
    bool right_is_closed;

    FlatInterval(int left_val, bool left_is_closed, int right_val,
                 bool right_is_closed)
        : left_val(left_val),
          left_is_closed(left_is_closed),
          right_val(right_val),
          right_is_closed(right_is_closed) {}

    explicit FlatInterval(Interval in)
        : left_val(in.left.val),
          left_is_closed(in.left.is_closed),
          right_val(in.right.val),
          right_is_closed(in.right.is_closed) {}

    operator Interval() const {
        return {{left_is_closed, left_val}, {right_is_closed, right_val}};
    }

    bool operator==(const FlatInterval& rhs) const {
        return tie(left_val, left_is_closed, right_val, right_is_closed) ==
               tie(rhs.left_val, rhs.left_is_closed, rhs.right_val,
                   rhs.right_is_closed);
    }
};

namespace test_framework {
template <>
struct SerializationTrait<FlatInterval>
    : UserSerTrait<FlatInterval, int, bool, int, bool> {};
}  // namespace test_framework

ostream& operator<<(ostream& out, const FlatInterval& i) {
    return out << (i.left_is_closed ? '<' : '(') << i.left_val << ", "
               << i.right_val << (i.right_is_closed ? '>' : ')');
}

vector<FlatInterval> UnionOfIntervalsWrapper(
    TimedExecutor& executor, const vector<FlatInterval>& intervals) {
    vector<Interval> casted;
    for (const FlatInterval& i : intervals) {
        casted.push_back(static_cast<Interval>(i));
    }

    vector<Interval> result =
        executor.Run([&] { return UnionOfIntervals(casted); });

    return {begin(result), end(result)};
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "intervals"};
    return GenericTestMain(args, "data.tsv", &UnionOfIntervalsWrapper,
                           DefaultComparator{}, param_names);
}
