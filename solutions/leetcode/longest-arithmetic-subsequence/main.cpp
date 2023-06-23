class Solution {
   public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        int result = 2;
        vector<vector<int>> dp(n, vector<int>(2 * (mx - mn) + 1, 1));
        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                int d = nums[r] - nums[l] + mx - mn;
                dp[r][d] = max(dp[r][d], dp[l][d] + 1);
                result = max(result, dp[r][d]);
            }
        }

        return result;
    }
};
