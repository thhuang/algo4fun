class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> points(max_num + 1, 0);
        for (int v : nums) ++points[v];

        if (points.size() == 1) return 0;
        array<int, 2> dp = {0, points[1]};

        for (int i = 2; i < points.size(); ++i) {
            dp = {dp[1], max(dp[0] + points[i] * i, dp[1])};
        }

        return dp.back();
    }
};
