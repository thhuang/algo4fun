class Solution {
    const int mod = 1e9 + 7;

   public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza.front().size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1, s = 0; j <= n; ++j) {
                s += pizza[i - 1][j - 1] == 'A';
                prefix[i][j] += prefix[i - 1][j] + s;
            }
        }

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        function<int(int, int, int)> dfs = [&](int x, int y, int t) -> int {
            if (dp[x][y][t] != -1) return dp[x][y][t];

            int s = prefix[m][n] + prefix[x][y] - prefix[m][y] - prefix[x][n];
            if (t > s) return dp[x][y][t] = 0;
            if (t == 1) return dp[x][y][t] = 1;

            long result = 0;
            for (int i = x + 1; i < m; ++i) {
                int v =
                    prefix[i][n] + prefix[x][y] - prefix[i][y] - prefix[x][n];
                if (v == 0) continue;
                result = (result + dfs(i, y, t - 1)) % mod;
            }
            for (int j = y + 1; j < n; ++j) {
                int v =
                    prefix[m][j] + prefix[x][y] - prefix[m][y] - prefix[x][j];
                if (v == 0) continue;
                result = (result + dfs(x, j, t - 1)) % mod;
            }

            return dp[x][y][t] = result;
        };

        return dfs(0, 0, k);
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza.front().size();

        vector<vector<int>> suffixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (pizza[i][j] == 'A') ++sum;
                suffixSum[i][j] = sum + suffixSum[i + 1][j];
            }
        }

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        function<int(int, int, int)> dp = [&](int r, int c, int want) -> int {
            if (want == 0 || suffixSum[r][c] == 0 || want > suffixSum[r][c])
                return 0;
            if (want == 1) return 1;
            if (memo[r][c][want] != -1) return memo[r][c][want];

            long long result = 0;

            for (int i = r + 1; i < m; ++i) {
                if (suffixSum[i][c] == 0 || suffixSum[r][c] == suffixSum[i][c])
                    continue;
                (result += dp(i, c, want - 1)) %= mod;
            }
            for (int j = c + 1; j < n; ++j) {
                if (suffixSum[r][j] == 0 || suffixSum[r][c] == suffixSum[r][j])
                    continue;
                (result += dp(r, j, want - 1)) %= mod;
            }

            return memo[r][c][want] = result;
        };

        return dp(0, 0, k);
    }
};

class Solution {
    const int mod = 1e9 + 7;

   public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza.front().size();

        vector<vector<int>> suffixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (pizza[i][j] == 'A') ++sum;
                suffixSum[i][j] = sum + suffixSum[i + 1][j];
            }
        }

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        for (int kk = 1; kk <= k; ++kk) {
            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    if (suffixSum[i][j] < kk) {
                        continue;
                    }
                    if (kk == 1) {
                        dp[i][j][kk] = 1;
                        continue;
                    }
                    long long result = 0;
                    for (int ii = i + 1; ii < m; ++ii) {
                        if (suffixSum[i][j] == suffixSum[ii][j]) continue;
                        if (suffixSum[ii][j] == 0) break;
                        (result += dp[ii][j][kk - 1]) %= mod;
                    }
                    for (int jj = j + 1; jj < n; ++jj) {
                        if (suffixSum[i][j] == suffixSum[i][jj]) continue;
                        if (suffixSum[i][jj] == 0) break;
                        (result += dp[i][jj][kk - 1]) %= mod;
                    }
                    dp[i][j][kk] = result;
                }
            }
        }

        return dp[0][0][k];
    }
};
