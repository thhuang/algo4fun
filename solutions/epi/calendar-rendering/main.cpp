#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <algorithm>
#include <vector>
using namespace std;

struct Event {
    int start, finish;
};

struct Endpoint {
    int time;
    int occup;

    bool operator<(const Endpoint& that) const {
        if (time == that.time) {
            return occup > that.occup;
        }
        return time < that.time;
    }
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
    vector<Endpoint> endpoints;
    for (auto e : A) {
        endpoints.push_back({e.start, 1});
        endpoints.push_back({e.finish, -1});
    }
    sort(begin(endpoints), end(endpoints));

    int max_occup = 0;
    int curr_occup = 0;
    for (auto e : endpoints) {
        curr_occup += e.occup;
        max_occup = max(max_occup, curr_occup);
    }

    return max_occup;
}

namespace test_framework {
template <>
struct SerializationTrait<Event> : UserSerTrait<Event, int, int> {};
}  // namespace test_framework

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"A"};
    return GenericTestMain(args, "data.tsv", &FindMaxSimultaneousEvents,
                           DefaultComparator{}, param_names);
}
