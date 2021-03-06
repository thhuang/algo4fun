#include <epi/generic_test.h>

#include <unordered_map>
#include <vector>
using namespace std;

bool CheckEntry(
    const vector<vector<int>>& grid, const vector<int>& pattern,
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>>& cache,
    int i, int j, int idx) {
    int n = size(grid);
    int m = size(grid[0]);
    if (idx == size(pattern)) return true;
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    if (grid[i][j] != pattern[idx]) return false;
    if (cache[i][j][idx]) return false;

    bool result = CheckEntry(grid, pattern, cache, i - 1, j, idx + 1) ||
                  CheckEntry(grid, pattern, cache, i + 1, j, idx + 1) ||
                  CheckEntry(grid, pattern, cache, i, j - 1, idx + 1) ||
                  CheckEntry(grid, pattern, cache, i, j + 1, idx + 1);

    if (!result) cache[i][j][idx] = true;
    return result;
}

bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
                              const vector<int>& pattern) {
    int n = size(grid);
    int m = size(grid[0]);
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> cache;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (CheckEntry(grid, pattern, cache, i, j, 0)) return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"grid", "pattern"};
    return GenericTestMain(args, "data.tsv", &IsPatternContainedInGrid,
                           DefaultComparator{}, param_names);
}
