class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;

   public:
    int numberOfArrays(string s, int k) {
        int n = s.size();

        vector<ll> dp(n + 1, 0);
        dp.front() = 1;

        for (int l = 1; l <= n; ++l) {
            ll v = 0;
            for (int r = l; r <= n; ++r) {
                v = v * 10 + (s[r - 1] - '0');
                if (v > k || v == 0) break;
                (dp[r] += dp[l - 1]) %= mod;
            }
        }

        return dp.back();
    }
};
