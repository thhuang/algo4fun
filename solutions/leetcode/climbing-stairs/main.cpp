class Solution {
   public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] += dp[i];
            if (i + 2 <= n) dp[i + 2] += dp[i];
        }
        return dp.back();
    }
};

class Solution {
   public:
    int climbStairs(int n) {
        array<int, 2> dp = {1, 1};
        for (int i = 2; i <= n; ++i) dp = {dp[1], dp[0] + dp[1]};
        return dp.back();
    }
};
