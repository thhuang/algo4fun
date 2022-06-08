class Solution {
    const int mod = 1e9 + 7;

   public:
    int numberOfWays(int numPeople) {
        vector<long> dp(numPeople + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= numPeople; i += 2) {
            long v = 0;
            for (int j = 1; j < i; j += 2) {
                v = (v + dp[j - 1] * dp[i - j - 1] % mod) % mod;
            }
            dp[i] = v;
        }
        return dp.back();
    }
};
