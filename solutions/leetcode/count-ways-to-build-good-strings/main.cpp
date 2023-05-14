class Solution {
    const int mod = 1e9 + 7;

   public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= high; ++i) {
            if (int j = i + zero; j <= high) (dp[j] += dp[i]) %= mod;
            if (int j = i + one; j <= high) (dp[j] += dp[i]) %= mod;
        }

        long long result = 0;
        for (int i = low; i <= high; ++i) (result += dp[i]) %= mod;

        return result;
    }
};
