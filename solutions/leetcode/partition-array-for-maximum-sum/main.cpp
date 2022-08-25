class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1, mx = numeric_limits<int>::min();
                 j <= k && i - j >= 0; ++j) {
                mx = max(mx, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + j * mx);
            }
        }
        return dp.back();
    }
};
