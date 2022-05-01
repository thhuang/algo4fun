class Solution {
   public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> wall_1_guard_2(m, vector<int>(n, 0));
        for (const auto& w : walls) wall_1_guard_2[w[0]][w[1]] = 1;
        for (const auto& g : guards) wall_1_guard_2[g[0]][g[1]] = 2;

        vector<vector<int>> grid(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            int state = 1;
            for (int j = 0; j < n; ++j) {
                if (wall_1_guard_2[i][j] == 1) {
                    state = 1;
                } else if (wall_1_guard_2[i][j] == 2) {
                    state = 2;
                } else if (state == 2) {
                    grid[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            int state = 1;
            for (int j = n - 1; ~j; --j) {
                if (wall_1_guard_2[i][j] == 1) {
                    state = 1;
                } else if (wall_1_guard_2[i][j] == 2) {
                    state = 2;
                } else if (state == 2) {
                    grid[i][j] = 2;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int state = 1;
            for (int i = 0; i < m; ++i) {
                if (wall_1_guard_2[i][j] == 1) {
                    state = 1;
                } else if (wall_1_guard_2[i][j] == 2) {
                    state = 2;
                } else if (state == 2) {
                    grid[i][j] = 2;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            int state = 1;
            for (int i = m - 1; ~i; --i) {
                if (wall_1_guard_2[i][j] == 1) {
                    state = 1;
                } else if (wall_1_guard_2[i][j] == 2) {
                    state = 2;
                } else if (state == 2) {
                    grid[i][j] = 2;
                }
            }
        }

        int count = m * n - guards.size() - walls.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) --count;
            }
        }

        return count;
    }
};
