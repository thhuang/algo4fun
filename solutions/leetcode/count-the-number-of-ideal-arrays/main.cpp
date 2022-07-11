// https://youtu.be/R7b6DY-3-7o
class Solution {
    const int mod = 1e9 + 7;

   public:
    int idealArrays(int n, int maxValue) {
        int k = 0;
        for (int v = 1; v <= maxValue; v <<= 1) ++k;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                for (int t = 0; t <= j; ++t) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - t]) % mod;
                }
            }
        }

        vector<int> primes = generatePrimes(maxValue);

        long long result = 0;
        for (int i = 1; i <= maxValue; ++i) {
            long long v = 1;
            for (int p : primes) {
                int x = i, count = 0;
                while (x % p == 0) {
                    x /= p;
                    ++count;
                }
                v = v * dp[n][count] % mod;
            }
            result = (result + v) % mod;
        }

        return result;
    }

    vector<int> generatePrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        vector<int> result;
        for (int i = 2; i <= n; ++i) {
            if (!primes[i]) continue;
            result.push_back(i);
            for (int j = i + i; j <= n; j += i) primes[j] = false;
        }

        return result;
    }
};
