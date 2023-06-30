class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto check = [&](int t) -> bool {
            queue<array<int, 2>> q;
            for (int j = 0; j < col; ++j) q.push({0, j});

            vector<vector<bool>> vis(row, vector<bool>(col, false));
            for (int i = 0; i <= t; ++i)
                vis[cells[i][0] - 1][cells[i][1] - 1] = true;

            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                if (i < 0 || row <= i || j < 0 || col <= j) continue;
                if (vis[i][j]) continue;
                vis[i][j] = true;

                if (i == row - 1) return true;

                for (auto [di, dj] : directions) q.push({i + di, j + dj});
            }

            return false;
        };

        int n = cells.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};
