class Solution {
    const int mod = 1e9 + 7;

    struct State {
        long long partial, full;
    };

   public:
    int numTilings(int n) {
        if (n < 3) return n;
        array<State, 2> dp = {State{0, 1}, {2, 2}};
        for (int i = 3; i <= n; ++i) {
            dp = {dp[1],
                  {(dp[0].full * 2 + dp[1].partial) % mod,
                   (dp[0].full + dp[1].partial + dp[1].full) % mod}};
        }
        return dp[1].full;
    }
};
