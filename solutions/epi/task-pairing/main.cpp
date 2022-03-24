#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <tuple>
#include <vector>
using namespace std;

struct PairedTasks {
    int task_1, task_2;
};

vector<PairedTasks> OptimumTaskAssignment(vector<int> task_durations) {
    sort(begin(task_durations), end(task_durations));

    vector<PairedTasks> pairs;
    int n = size(task_durations);
    int l = 0, r = n - 1;
    if (n & 1) {
        l = 1;
        pairs.push_back({task_durations[0], 0});
    }

    while (l < r) {
        pairs.push_back({task_durations[l++], task_durations[r--]});
    }

    return pairs;
}

namespace test_framework {
template <>
struct SerializationTrait<PairedTasks> : UserSerTrait<PairedTasks, int, int> {};
}  // namespace test_framework

bool operator==(const PairedTasks& lhs, const PairedTasks& rhs) {
    return tie(lhs.task_1, lhs.task_2) == tie(rhs.task_1, rhs.task_2);
}

ostream& operator<<(ostream& out, const PairedTasks& t) {
    return PrintTo(out, make_tuple(t.task_1, t.task_2));
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"task_durations"};
    return GenericTestMain(args, "data.tsv", &OptimumTaskAssignment,
                           DefaultComparator{}, param_names);
}
