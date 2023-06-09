class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<string, int> row;
        for (int i = 0; i < n; ++i) {
            stringstream ss;
            for (int j = 0; j < n; ++j) {
                ss << grid[i][j] << ' ';
            }
            ++row[ss.str()];
        }

        unordered_map<string, int> col;
        for (int j = 0; j < n; ++j) {
            stringstream ss;
            for (int i = 0; i < n; ++i) {
                ss << grid[i][j] << ' ';
            }
            ++col[ss.str()];
        }

        int result = 0;
        for (auto [s, v] : row) {
            result += col[s] * v;
        }

        return result;
    }
};
