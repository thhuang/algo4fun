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

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << suffixSum[i][j] << ' ';
            }
            cout << '\n';
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
