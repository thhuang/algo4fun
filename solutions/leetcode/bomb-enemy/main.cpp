class Solution {
   public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<vector<int>> counts(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0, c = 0; j < m; ++j) {
                if (grid[i][j] == 'W') {
                    c = 0;
                } else if (grid[i][j] == 'E') {
                    ++c;
                } else {
                    counts[i][j] += c;
                }
            }
            for (int j = m - 1, c = 0; ~j; --j) {
                if (grid[i][j] == 'W') {
                    c = 0;
                } else if (grid[i][j] == 'E') {
                    ++c;
                } else {
                    counts[i][j] += c;
                }
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0, c = 0; i < n; ++i) {
                if (grid[i][j] == 'W') {
                    c = 0;
                } else if (grid[i][j] == 'E') {
                    ++c;
                } else {
                    counts[i][j] += c;
                }
            }
            for (int i = n - 1, c = 0; ~i; --i) {
                if (grid[i][j] == 'W') {
                    c = 0;
                } else if (grid[i][j] == 'E') {
                    ++c;
                } else {
                    counts[i][j] += c;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = max(result, counts[i][j]);
            }
        }

        return result;
    }
};
