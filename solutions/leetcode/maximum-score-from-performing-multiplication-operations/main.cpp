class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; --i) {
            for (int l = 0; l <= i; ++l) {
                int k = multipliers[i];
                dp[i][l] = max(k * nums[l] + dp[i + 1][l + 1],
                               k * nums[n - i + l - 1] + dp[i + 1][l]);
            }
        }

        return dp[0][0];
    }
};
