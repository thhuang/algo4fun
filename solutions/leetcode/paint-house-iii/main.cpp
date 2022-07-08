class Solution {
    const int MAX = 1e9;

   public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
                int target) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(target + 1, vector<int>(n + 1, MAX)));

        if (houses[0] != 0) {
            dp[0][1][houses[0]] = 0;
        } else {
            for (int i = 1; i <= n; ++i) dp[0][1][i] = cost[0][i - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int t = 1; t <= target; ++t) {
                for (int curr = 1; curr <= n; ++curr) {
                    if (houses[i] != 0 && houses[i] != curr) continue;
                    int c = houses[i] == curr ? 0 : cost[i][curr - 1];
                    for (int prev = 1; prev <= n; ++prev) {
                        int dt = curr != prev;
                        dp[i][t][curr] =
                            min(dp[i][t][curr], dp[i - 1][t - dt][prev] + c);
                    }
                }
            }
        }

        int result = MAX;
        for (int v : dp.back().back()) result = min(result, v);

        if (result == MAX) return -1;
        return result;
    }
};
