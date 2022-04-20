class Solution {
   public:
    int rob(vector<int>& nums) {
        if (size(nums) == 0) return 0;
        if (size(nums) == 1) return nums[0];
        if (size(nums) == 2) return max(nums[0], nums[1]);

        array<int, 2> dp = {0, nums[0]};
        for (int i = 1; i < size(nums) - 1; ++i) {
            dp = {dp[1], max(dp[1], dp[0] + nums[i])};
        }
        int mem = dp.back();

        dp = {0, nums[1]};
        for (int i = 2; i < size(nums); ++i) {
            dp = {dp[1], max(dp[1], dp[0] + nums[i])};
        }

        return max(mem, dp.back());
    }
};

class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        auto simple_rob = [&](int l, int r) -> int {
            array<int, 2> dp = {0, 0};
            for (int i = l; i <= r; ++i) {
                dp = {dp[1], max(dp[1], dp[0] + nums[i])};
            }
            return dp.back();
        };

        return max(simple_rob(0, nums.size() - 2),
                   simple_rob(1, nums.size() - 1));
    }
};
