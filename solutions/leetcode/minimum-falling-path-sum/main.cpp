class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> dp = matrix.front();
        for (int i = 1; i < m; ++i) {
            vector<int> new_dp(n);
            for (int j = 0; j < n; ++j) {
                new_dp[j] = dp[j];
                if (j - 1 >= 0) new_dp[j] = min(new_dp[j], dp[j - 1]);
                if (j + 1 < n) new_dp[j] = min(new_dp[j], dp[j + 1]);
                new_dp[j] += matrix[i][j];
            }
            dp = move(new_dp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};
