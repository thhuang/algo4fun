class Solution {
    const int mod = 1e9 + 7;
    typedef long long ll;

   public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<ll>> dp(goal + 1, vector<ll>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % mod;
                if (j > k) {
                    (dp[i][j] += dp[i - 1][j] * (j - k)) %= mod;
                }
            }
        }
        return dp[goal][n];
    }
};

class Solution {
    const int mod = 1e9 + 7;
    typedef long long ll;

   public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= goal; ++i) {
            vector<ll> dpNew(n + 1, 0);
            for (int j = min(i, n); j >= 1; --j) {
                dpNew[j] = dp[j - 1] * (n - j + 1) % mod;
                if (j > k) {
                    (dpNew[j] += dp[j] * (j - k)) %= mod;
                }
            }
            dp = move(dpNew);
        }
        return dp[n];
    }
};
