class Solution {
   public:
    int jump(vector<int>& nums) {
        const int int_max = numeric_limits<int>::max();
        vector<int> dp(size(nums), int_max);
        dp[0] = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (dp[i] == int_max) continue;
            for (int d = 1; d <= nums[i]; ++d) {
                if (i + d >= size(dp)) break;
                dp[i + d] = min(dp[i + d], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
