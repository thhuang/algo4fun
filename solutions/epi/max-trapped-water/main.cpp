#include <epi/generic_test.h>

#include <vector>
using namespace std;

int GetMaxTrappedWater(const vector<int>& heights) {
    int water = 0;
    int l = 0, r = size(heights) - 1;
    while (l < r) {
        int h = min(heights[l], heights[r]);
        int w = r - l;
        water = max(water, h * w);
        if (heights[l] < heights[r]) {
            ++l;
        } else {
            --r;
        }
    }
    return water;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"heights"};
    return GenericTestMain(args, "data.tsv", &GetMaxTrappedWater,
                           DefaultComparator{}, param_names);
}
