class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);

        queue<array<int, 3>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        while (!empty(q)) {
            auto [i, j, d] = q.front();
            q.pop();

            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (grid[i][j] == 0) continue;
            if (vis[i][j]) continue;

            ans = max(ans, d);
            vis[i][j] = true;

            for (auto [di, dj] : directions) q.push({i + di, j + dj, d + 1});
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        queue<array<int, 3>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        vector<vector<int>> time(m, vector<int>(n, -1));
        while (!q.empty()) {
            auto [i, j, t] = q.front();
            q.pop();

            if (time[i][j] != -1) continue;
            time[i][j] = t;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (grid[ii][jj] == 0 || time[ii][jj] != -1) continue;
                q.push({ii, jj, t + 1});
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (time[i][j] == -1 && grid[i][j] == 1) return -1;
                result = max(result, time[i][j]);
            }
        }

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int cnt = 0;
        queue<array<int, 3>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                ++cnt;

                if (grid[i][j] == 2) q.push({i, j, 0});
                grid[i][j] = 1;
            }

        int result = 0;
        while (!q.empty()) {
            auto [i, j, min] = q.front();
            q.pop();

            if (i < 0 || m <= i || j < 0 || n <= j) continue;
            if (grid[i][j] != 1) continue;
            grid[i][j] = 2;

            --cnt;
            result = max(result, min);

            for (auto [di, dj] : directions) q.push({i + di, j + dj, min + 1});
        }

        return cnt == 0 ? result : -1;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        queue<array<int, 2>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int result = 0;
        while (true) {
            int k = q.size();
            while (k--) {
                auto [i, j] = q.front();
                q.pop();
                for (auto [di, dj] : directions) {
                    int ii = i + di, jj = j + dj;
                    if (ii < 0 || m <= ii || jj < 0 || n <= jj ||
                        grid[ii][jj] != 1)
                        continue;
                    grid[ii][jj] = 2;
                    q.push({ii, jj});
                }
            }

            if (q.empty()) break;
            ++result;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    struct RottingStep {
        int i, j, step;
    };

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        queue<RottingStep> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                    q.push({i, j, 0});
                }
            }
        }

        int result = 0;

        while (!q.empty()) {
            auto [i, j, step] = q.front();
            q.pop();

            if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] != 1) continue;

            result = step;
            grid[i][j] = 2;

            for (auto [di, dj] : directions) {
                q.push({i + di, j + dj, step + 1});
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return result;
    }
};
