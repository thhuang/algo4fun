class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m) return 0;
            if (grid[i][j] != 1) return 0;

            grid[i][j] = 2;

            int sum = 1;
            for (auto [di, dj] : directions) {
                sum += dfs(i + di, j + dj);
            }
            return sum;
        };

        for (int i = 0; i < n; ++i) dfs(i, 0), dfs(i, m - 1);
        for (int j = 0; j < m; ++j) dfs(0, j), dfs(n - 1, j);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                count += dfs(i, j);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) grid[i][j] = 1;
            }
        }

        return count;
    }
};
