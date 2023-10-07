class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;

   public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<ll>>> memo(
            n, vector<vector<ll>>(m + 1, vector<ll>(k + 1, -1)));
        function<ll(int, int, int)> dp = [&](int i, int mx, int remain) -> ll {
            if (remain < 0) return 0;
            if (i == n) {
                if (remain == 0) return 1;
                return 0;
            }
            if (memo[i][mx][remain] != -1) return memo[i][mx][remain];

            ll result = 0;
            for (int v = 1; v <= m; ++v) {
                if (v <= mx) {
                    (result += dp(i + 1, mx, remain)) %= mod;
                } else {
                    (result += dp(i + 1, v, remain - 1)) %= mod;
                }
            }

            return memo[i][mx][remain] = result;
        };

        return dp(0, 0, k);
    }
};
