class Solution {
   public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;

        int n3 = n / 3;
        if ((n3 & 1) ^ (n & 1)) --n3;
        int n2 = (n - 3 * n3) / 2;

        return pow(2, n2) * pow(3, n3);
    }
};

class Solution {
   public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        array<int, 3> dp = {1, 2, 3};
        for (int i = 4; i <= n; ++i) {
            dp = {dp[1], dp[2], max(dp[0] * 3, dp[1] * 2)};
        }
        return dp.back();
    }
};
