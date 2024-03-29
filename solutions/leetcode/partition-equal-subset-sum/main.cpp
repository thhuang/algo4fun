class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int v : nums) sum += v;
        if (sum & 1) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            for (int j = target; j - v >= 0; --j) {
                dp[j] = dp[j] || dp[j - v];
            }
            if (dp.back()) return true;
        }

        return false;
    }
};

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;

        vector<bool> dp(total / 2 + 1, false);
        dp[0] = true;

        for (int v : nums) {
            for (int i = dp.size(); i >= 0; --i) {
                int j = i + v;
                if (!dp[i] || j > dp.size()) continue;
                dp[j] = true;
            }
        }

        return dp.back();
    }
};
