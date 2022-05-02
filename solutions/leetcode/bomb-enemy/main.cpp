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

class Solution {
   public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int result = 0;

        vector<int> col_hits(m, 0);
        for (int i = 0, row_hits = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    row_hits = 0;
                    for (int k = j; k < m && grid[i][k] != 'W'; ++k) {
                        row_hits += grid[i][k] == 'E';
                    }
                }

                if (i == 0 || grid[i - 1][j] == 'W') {
                    col_hits[j] = 0;
                    for (int k = i; k < n && grid[k][j] != 'W'; ++k) {
                        col_hits[j] += grid[k][j] == 'E';
                    }
                }

                if (grid[i][j] == '0') {
                    result = max(result, row_hits + col_hits[j]);
                }
            }
        }

        return result;
    }
};
