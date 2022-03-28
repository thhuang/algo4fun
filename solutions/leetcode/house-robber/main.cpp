class Solution {
   public:
    int rob(vector<int>& nums) {
        if (size(nums) == 0) return 0;
        if (size(nums) == 1) return nums[0];

        array<int, 2> dp = {0, nums[0]};
        for (int i = 1; i < size(nums); ++i) {
            dp = {dp[1], max(dp[1], dp[0] + nums[i])};
        }

        return dp.back();
    }
};
