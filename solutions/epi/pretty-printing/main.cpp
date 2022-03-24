#include <epi/generic_test.h>

#include <string>
#include <vector>
using namespace std;

int MinimumMessiness(const vector<string>& words, int line_length) {
    vector<int> minimum_messiness(size(words), numeric_limits<int>::max());
    int r = line_length - size(words[0]);
    minimum_messiness[0] = r * r;

    for (int i = 1; i < size(words); ++i) {
        r = line_length - size(words[i]);
        minimum_messiness[i] = minimum_messiness[i - 1] + r * r;

        for (int j = i - 1; j >= 0; --j) {
            r -= size(words[j]) + 1;
            if (r < 0) break;

            int prev_messiness = j - 1 < 0 ? 0 : minimum_messiness[j - 1];
            minimum_messiness[i] =
                min(minimum_messiness[i], prev_messiness + r * r);
        }
    }

    return minimum_messiness.back();
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"words", "line_length"};
    return GenericTestMain(args, "data.tsv", &MinimumMessiness,
                           DefaultComparator{}, param_names);
}
