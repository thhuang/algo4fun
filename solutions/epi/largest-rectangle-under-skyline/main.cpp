#include <epi/generic_test.h>

#include <algorithm>
#include <vector>
using namespace std;

int CalculateLargestRectangle(const vector<int>& heights) {
    struct HeightPos {
        int height, pos;
    };

    int max_rect = 0;
    vector<HeightPos> left_bounds;

    for (int i = 0; i < size(heights); ++i) {
        HeightPos height_pos = {heights[i], i};
        while (!empty(left_bounds) && left_bounds.back().height >= heights[i]) {
            height_pos = left_bounds.back();

            int rect = height_pos.height * (i - height_pos.pos);
            max_rect = max(max_rect, rect);

            height_pos.height = heights[i];
            left_bounds.pop_back();
        }

        left_bounds.push_back(height_pos);
    }

    for (auto hp : left_bounds) {
        int rect = hp.height * (size(heights) - hp.pos);
        max_rect = max(max_rect, rect);
    }

    return max_rect;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"heights"};
    return GenericTestMain(args, "data.tsv", &CalculateLargestRectangle,
                           DefaultComparator{}, param_names);
}
