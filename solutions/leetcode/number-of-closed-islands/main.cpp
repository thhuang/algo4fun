class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (grid[i][j] != 0) return;
            grid[i][j] = 2;
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        for (int i = 0; i < n; ++i) dfs(i, 0), dfs(i, m - 1);
        for (int i = 0; i < m; ++i) dfs(0, i), dfs(n - 1, i);

        int count = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (grid[i][j] != 0) continue;
                dfs(i, j);
                ++count;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) grid[i][j] = 0;
            }
        }

        return count;
    }
};
