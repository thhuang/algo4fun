class Solution {
    const int mod = 1e9 + 7;
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) return 0;
            if (grid[i][j] <= p) return 0;
            if (dp[i][j] != -1) return dp[i][j];

            long long v = 1;
            for (auto [di, dj] : directions) {
                v = (v + dfs(i + di, j + dj, grid[i][j])) % mod;
            }
            return dp[i][j] = v;
        };

        long long result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result = (result + dfs(i, j, 0)) % mod;
            }
        }

        return result;
    }
};

class Solution {
    const int mod = 1e9 + 7;
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
            if (i < 0 || m <= i || j < 0 || n <= j) return -1;
            if (p >= grid[i][j]) return -1;
            if (dp[i][j] != -1) return dp[i][j];

            long long result = 0;
            for (auto [di, dj] : directions) {
                (result += dfs(i + di, j + dj, grid[i][j]) + 1) %= mod;
            }

            return dp[i][j] = result;
        };

        long long result = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                (result += dfs(i, j, 0)) %= mod;
            }
        }

        return result;
    }
};
