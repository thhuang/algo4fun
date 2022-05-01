class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        vector<vector<int>> fire(n, vector<int>(m, -1));
        vector<array<int, 2>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) q.push_back({i, j});
            }
        }
        int t = 0;
        while (!q.empty()) {
            vector<array<int, 2>> new_q;
            for (auto [i, j] : q) {
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (grid[i][j] == 2) continue;
                if (fire[i][j] != -1) continue;
                fire[i][j] = t;
                for (auto [di, dj] : directions)
                    new_q.push_back({i + di, j + dj});
            }
            ++t;
            q = move(new_q);
        }

        vector<vector<int>> required(n, vector<int>(m, -1));
        q = {{0, 0}};
        t = 0;
        while (!q.empty()) {
            vector<array<int, 2>> new_q;
            for (auto [i, j] : q) {
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (grid[i][j] == 2) continue;
                if (required[i][j] != -1) continue;
                required[i][j] = t;
                for (auto [di, dj] : directions)
                    new_q.push_back({i + di, j + dj});
            }
            ++t;
            q = move(new_q);
        }

        if (required.back().back() == -1) return -1;
        if (fire.back().back() == -1) return 1e9;
        if (required.back().back() > fire.back().back()) return -1;

        int result = fire.back().back() - required.back().back();
        if (n - 2 >= 0 && fire[n - 2][m - 1] - required[n - 2][m - 1] > result)
            return result;
        if (m - 2 >= 0 && fire[n - 1][m - 2] - required[n - 1][m - 2] > result)
            return result;
        return result - 1;
    }
};
