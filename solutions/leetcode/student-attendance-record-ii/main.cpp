class Solution {
    struct DP {
        long long a0l0, a0l1, a0l2, a1l0, a1l1, a1l2;
    };

    const int mod = 1e9 + 7;

   public:
    int checkRecord(int n) {
        DP dp = {1, 1, 0, 1, 0, 0};
        for (int i = 1; i < n; ++i) {
            dp = {(dp.a0l0 + dp.a0l1 + dp.a0l2) % mod,
                  dp.a0l0,
                  dp.a0l1,
                  (dp.a0l0 + dp.a0l1 + dp.a0l2 + dp.a1l0 + dp.a1l1 + dp.a1l2) % mod,
                  dp.a1l0,
                  dp.a1l1};
        }
        return (dp.a0l0 + dp.a0l1 + dp.a0l2 + dp.a1l0 + dp.a1l1 + dp.a1l2) % mod;
    }
};
