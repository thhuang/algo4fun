class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int v : nums) total += v;

        if (target < -total || total < target) return 0;

        unordered_map<int, int> dp = {{0, 1}};
        for (int v : nums) {
            unordered_map<int, int> new_dp;
            for (auto [sum, count] : dp) {
                new_dp[sum + v] += count;
                new_dp[sum - v] += count;
            }
            dp = move(new_dp);
        }

        return dp[target];
    }
};

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int v : nums) total += v;

        if (target < -total || total < target) return 0;

        vector<int> dp(total * 2 + 1, 0);
        dp[total] = 1;
        for (int v : nums) {
            vector<int> new_dp(dp.size(), 0);
            for (int i = v; i < dp.size() - v; ++i) {
                new_dp[i + v] += dp[i];
                new_dp[i - v] += dp[i];
            }
            dp = move(new_dp);
        }

        return dp[target + total];
    }
};
