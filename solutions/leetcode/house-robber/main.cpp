
class Solution {
   public:
    int rob(vector<int>& nums) {
        array<int, 2> dp = {0, 0};
        for (int v : nums) dp = {dp[1], max(dp[1], dp[0] + v)};
        return dp.back();
    }
};
