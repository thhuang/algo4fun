class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        vector<int> prev(m, 0);
        int sum = 0;
        for (int i = 0; i < m; ++i) prev[i] = sum += grid[0][i];

        for (int i = 1; i < n; ++i) {
            vector<int> curr = grid[i];
            curr[0] += prev[0];
            for (int j = 1; j < m; ++j) {
                curr[j] += min(curr[j - 1], prev[j]);
            }
            prev = move(curr);
        }

        return prev.back();
    }
};

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        vector<int> dp = grid.front();
        for (int i = 0, sum = 0; i < m; ++i) dp[i] = sum += grid.front()[i];

        for (int i = 1; i < n; ++i) {
            vector<int> new_dp = grid[i];

            for (int j = 0; j < m; ++j) {
                int v = dp[j];
                if (j > 0) v = min(v, new_dp[j - 1]);
                new_dp[j] += v;
            }

            dp = move(new_dp);
        }

        return dp.back();
    }
};

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid.back().back();
    }
};

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> dp(n, numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 0; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        return dp.back();
    }
};
