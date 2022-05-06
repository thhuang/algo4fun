class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int v : nums) total_sum += v;

        if (total_sum & 1) return false;

        int target_sum = total_sum / 2;
        vector<bool> dp(target_sum + 1, false);
        dp[0] = true;

        for (int v : nums) {
            for (int i = dp.size() - 1; ~i; --i) {
                if (i - v < 0) continue;
                dp[i] = dp[i] || dp[i - v];
            }
        }

        return dp.back();
    }
};

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int v : nums) total += v;

        if (total & 1) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int v : nums) {
            if (target - v >= 0 && dp[target - v]) return true;
            for (int i = dp.size() - 1; ~i; --i) {
                if (i - v < 0) continue;
                dp[i] = dp[i] || dp[i - v];
            }
        }

        return false;
    }
};
