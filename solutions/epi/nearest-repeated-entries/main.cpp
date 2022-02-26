#include <epi/generic_test.h>

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int FindNearestRepetition(const vector<string>& paragraph) {
    int nearest_dist = size(paragraph);
    unordered_map<string, int> word_pos;
    for (int i = 0; i < size(paragraph); ++i) {
        string word = paragraph[i];
        auto it = word_pos.find(word);
        if (it != end(word_pos))
            nearest_dist = min(nearest_dist, i - it->second);

        word_pos[word] = i;
    }

    return nearest_dist == size(paragraph) ? -1 : nearest_dist;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"paragraph"};
    return GenericTestMain(args, "data.tsv", &FindNearestRepetition,
                           DefaultComparator{}, param_names);
}
