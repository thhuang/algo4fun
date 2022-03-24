#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <vector>
using namespace std;

const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance
// city i to the next city.
int FindAmpleCity(const vector<int>& gallons, const vector<int>& distances) {
    int current_distance_left = gallons.back() * kMPG - distances.back();
    int minimum_distance_left = current_distance_left;
    int city = 0;
    for (int i = 1; i < size(gallons); ++i) {
        current_distance_left += gallons[i - 1] * kMPG - distances[i - 1];
        if (current_distance_left < minimum_distance_left) {
            minimum_distance_left = current_distance_left;
            city = i;
        }
    }

    return city;
}

void FindAmpleCityWrapper(TimedExecutor& executor, const vector<int>& gallons,
                          const vector<int>& distances) {
    int result =
        executor.Run([&] { return FindAmpleCity(gallons, distances); });
    const int num_cities = gallons.size();
    int tank = 0;
    for (int i = 0; i < num_cities; ++i) {
        int city = (result + i) % num_cities;
        tank += gallons[city] * kMPG - distances[city];
        if (tank < 0) {
            throw TestFailure(FmtStr("Out of gas on city {}", i));
        }
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "gallons", "distances"};
    return GenericTestMain(args, "data.tsv", &FindAmpleCityWrapper,
                           DefaultComparator{}, param_names);
}
