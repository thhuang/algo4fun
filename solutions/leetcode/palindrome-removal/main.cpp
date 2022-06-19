class Solution {
   public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int l = 0, r = 1; r < n; ++l, ++r) dp[l][r] = arr[l] == arr[r] ? 1 : 2;

        for (int d = 3; d <= n; ++d) {
            for (int l = 0, r = l + d - 1; r < n; ++l, ++r) {
                if (arr[l] == arr[r]) {
                    dp[l][r] = dp[l + 1][r - 1];
                }
                for (int m = l; m < r; ++m) {
                    dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
                }
            }
        }

        return dp.front().back();
    }
};
