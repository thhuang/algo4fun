#include <epi/generic_test.h>

#include <vector>
using namespace std;

int MinimumTotalWaitingTime(vector<int> service_times) {
    sort(begin(service_times), end(service_times));

    int total_waiting_time = 0;
    int n = size(service_times);
    for (int i = 0; i < n; ++i) {
        total_waiting_time += service_times[i] * (n - i - 1);
    }

    return total_waiting_time;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"service_times"};
    return GenericTestMain(args, "data.tsv", &MinimumTotalWaitingTime,
                           DefaultComparator{}, param_names);
}
