class Solution {
   public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> sum(n + 1, 0);
        for (int i = n - 1, s = 0; i >= 0; --i) {
            sum[i] = s += piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        function<int(int, int)> dfs = [&](int i, int m) -> int {
            if (i == n) return 0;

            m = min(m, n);
            if (dp[i][m] != -1) return dp[i][m];

            int result = 0;
            for (int x = 1, v = 0; x <= m * 2 && i + x - 1 < n; ++x) {
                v += piles[i + x - 1];
                result = max(result, v + sum[i + x] - dfs(i + x, max(x, m)));
            }

            return dp[i][m] = result;
        };

        return dfs(0, 1);
    }
};
