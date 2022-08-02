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
