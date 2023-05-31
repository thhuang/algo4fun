class Solution {
   public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = max(piles[i], piles[i + 1]);
        }

        for (int d = 3; d <= n; ++d) {
            for (int l = 0; l + d - 1 < n; ++l) {
                int r = l + d - 1;

                int vl = piles[l] + min(dp[l + 2][r], dp[l + 1][r - 1]);
                int vr = piles[r] + min(dp[l + 1][r - 1], dp[l][r - 2]);

                dp[l][r] = max(vl, vr);
            }
        }

        int sum = accumulate(piles.begin(), piles.end(), 0);
        return dp.front().back() * 2 > sum;
    }
};
