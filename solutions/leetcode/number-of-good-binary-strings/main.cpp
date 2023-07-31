class Solution {
    const int mod = 1e9 + 7;

   public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup,
                          int zeroGroup) {
        vector<int> dp(maxLength + 1, 0);
        dp[0] = 1;

        int result = 0;
        for (int i = 1; i <= maxLength; ++i) {
            if (i >= oneGroup) (dp[i] += dp[i - oneGroup]) %= mod;
            if (i >= zeroGroup) (dp[i] += dp[i - zeroGroup]) %= mod;
            if (i >= minLength) (result += dp[i]) %= mod;
        }

        return result;
    }
};
