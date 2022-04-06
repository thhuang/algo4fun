class Solution {
   public:
    int rob(vector<int>& nums) {
        array<int, 2> dp = {0, 0};
        for (int i = 0; i < size(nums); ++i) {
            dp = {dp[1], max(dp[1], dp[0] + nums[i])};
        }
        return dp.back();
    }
};
