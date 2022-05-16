class Solution {
    vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        auto check = [&](int i, int j) -> bool {
            if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] != -1)
                return false;
            return true;
        };

        deque<array<int, 2>> q = {{0, 0}};
        for (int c = 0; c < m + n; ++c) {
            vector<array<int, 2>> targets;
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop_front();

                if (!check(i, j)) continue;
                if (i == m - 1 && j == n - 1) return c;

                targets.push_back({i, j});
                vis[i][j] = c;

                auto [di, dj] = directions[grid[i][j] - 1];
                q.push_back({i + di, j + dj});
            }

            for (auto [i, j] : targets) {
                for (auto [di, dj] : directions) {
                    if (check(i + di, j + dj)) {
                        q.push_back({i + di, j + dj});
                    }
                }
            }
        }

        return m + n - 1;
    }
};
