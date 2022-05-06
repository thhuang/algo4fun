class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int v : nums) total += v;

        if (target < -total || total < target) return 0;

        unordered_map<int, int> sum_ways = {{0, 1}};
        for (int v : nums) {
            unordered_map<int, int> new_sum_ways;
            for (auto [s, w] : sum_ways) {
                new_sum_ways[s + v] += sum_ways[s];
                new_sum_ways[s - v] += sum_ways[s];
            }
            sum_ways = move(new_sum_ways);
        }

        return sum_ways[target];
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
