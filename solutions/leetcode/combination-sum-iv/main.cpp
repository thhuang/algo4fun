class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int v : nums) {
                if (i - v < 0) continue;
                dp[i] += dp[i - v];
            }
        }
        return dp.back();
    }
};
