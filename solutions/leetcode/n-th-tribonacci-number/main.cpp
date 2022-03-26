class Solution {
   public:
    int tribonacci(int n) {
        array<int, 3> dp = {0, 1, 1};
        if (n < 3) return dp[n];
        for (int i = 3; i <= n; ++i) dp = {dp[1], dp[2], dp[0] + dp[1] + dp[2]};
        return dp.back();
    }
};
